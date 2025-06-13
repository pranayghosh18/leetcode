class Solution {
public:
// space from the begining merge approacj
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });

    vector<vector<int>> res = {intervals[0]};
    for(int i=1; i<intervals.size(); i++){
        // if not overlapping 
        if(res.back().back() < intervals[i][0]) res.push_back(intervals[i]);
        else{
            res.back().back() = max(res.back().back(), intervals[i][1]);
        }
    }
    return res;
}
};