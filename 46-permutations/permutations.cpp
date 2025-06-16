class Solution {
public:
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> store;
    if(nums.size() == 1) return {{nums[0]}};
    vector<int> left;
    for(int i=0; i<nums.size(); i++){
        vector<int> rest;
        rest.insert(rest.end(), left.begin(), left.end());
        rest.insert(rest.end(), nums.begin()+i+1, nums.end());
        vector<vector<int>> subRes = permute(rest);
        for(auto r : subRes){
            vector<int> tmp = {nums[i]};
            tmp.insert(tmp.end(), r.begin(), r.end());
            store.push_back(tmp);
        }
        left.push_back(nums[i]);
    }
    return store;
}
};