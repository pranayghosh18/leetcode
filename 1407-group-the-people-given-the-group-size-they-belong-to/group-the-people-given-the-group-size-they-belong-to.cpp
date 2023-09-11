class Solution {
public:
    vector<vector<int>> chop_off(vector<int>& v, int k){
    int chops = v.size()/k;
    vector<vector<int>> res(chops, vector<int>(k));
    int i(0);
    for(int c=0; c<chops; c++){
        for(int j=0; j<k; j++) res[c][j] = v[i++];
    }
    return res;
}
vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int,vector<int>> hm;
    for(int i=0; i<groupSizes.size(); i++) hm[ groupSizes[i] ].push_back(i);
    vector<vector<int>> res;
    for(auto i : hm){
        for(auto j : chop_off(i.second,i.first)) res.push_back(j);
    }
    return res;
}
};