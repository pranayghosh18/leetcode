class Solution {
public:
int maxEvents(vector<vector<int>>& events) {
    // sort on starting
    sort(events.begin(), events.end());
    int attempt(0);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxDays(-1);
    for(auto e : events) maxDays = max(maxDays, e[1]);
    int eventIndex(0);
    for(int d=1; d<=maxDays; d++){
        // 3. throw the events can't go with anymore
        while (!minHeap.empty() && minHeap.top() < d) minHeap.pop();
        // 1. store the events can attend
        while (eventIndex < events.size() && events[eventIndex][0] == d) minHeap.push(events[eventIndex][1]), eventIndex++;
        // 2. take the event ending most early
        if(minHeap.size() > 0) minHeap.pop(), attempt++;
    }
    return attempt;
}
};