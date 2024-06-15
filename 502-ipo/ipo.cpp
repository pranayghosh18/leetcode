class Solution {
public:

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    vector<pair<int,int>> capToProfit(profits.size());
    for(int i=0; i<capital.size(); i++) capToProfit[i] = {capital[i], profits[i]};
    sort(capToProfit.begin(), capToProfit.end());

    priority_queue<int> maxHeap;
    int i(0);
    while (k-- > 0)
    {
        while(i<capToProfit.size() && w >= capToProfit[i].first) maxHeap.push(capToProfit[i++].second);
        if(maxHeap.empty()) return w;
        w += maxHeap.top();
        maxHeap.pop();
    }
    
    return w;
}
};