class Solution {
public:

// sort on start vals
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int deleted(0);
    int prevEnd(intervals[0][1]);
    for(int i=1; i<intervals.size(); i++){
        // no overlap
        if(intervals[i][0] >= prevEnd) prevEnd = intervals[i][1];
        else{
            // have to delete one, but the one with ends first should be taken
            prevEnd = min(prevEnd, intervals[i][1]);
            deleted++;
        }
    }
    return deleted;
}
};