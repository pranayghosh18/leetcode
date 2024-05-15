class Solution {
public:
// , remove all intervals that are covered by another interval in the list.
bool static compare(vector<int>&a, vector<int>&b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    int i(0), j(1), emmerged(0);        

    while(j<intervals.size()){
        // intervals[i][0] <= intervals[j][0] --> known
        // emmerged
        if(intervals[j][1] <= intervals[i][1]){
            emmerged++;
            j++;
        }
        // no realtion
        // else if(intervals[i][1] < intervals[j][0]){
        //     i = j;
        //     j++;
        // }
        // if criss cross then update
        else{
            // intervals[i][1] = max(intervals[i][1], intervals[j][1]);
            i = j;
            j++;
        }
    }

    return intervals.size()-emmerged;
}
};

/*

---
  ---
 -------- 

*/