class Solution {
public:
int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTimes;
        freeTimes.push_back(startTime[0]);
        for(int i=1; i<startTime.size(); i++) freeTimes.push_back(startTime[i] - endTime[i-1]);
        freeTimes.push_back(eventTime - endTime.back());
        // grouping K meeting actually aggregate K+1 free zones
        // simple sliding window of size K+1
        int totalFree(0), maxFree(0);
        for(int r=0, f=0; r<freeTimes.size(); r++){
            totalFree += freeTimes[r];
            if(r-f >= k+1) totalFree -= freeTimes[f++];
            maxFree = max(maxFree, totalFree);
        }
        return maxFree;
    }
};