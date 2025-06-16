class Solution {
public:
    
void dfs(vector<int>& ar, int i, vector<int>& taken, vector<vector<int>>& res){
    if(i == ar.size()) {
        res.push_back(taken);
        return;
    }
    // dont take the current index
    int j=i;
    while(j < ar.size() && ar[j] == ar[i]) j++;
    dfs(ar, j, taken, res);

    // take the current index element
    taken.push_back(ar[i]);
    dfs(ar, i+1, taken, res);
    taken.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> taken;
    dfs(nums, 0, taken, res);
    return res;
}
};