class Solution {
public:
    int reductionOperations(vector<int>& nums) {
    map<int,int,greater<int>> hm;
    for(int i: nums) hm[i]++;
    int res(0);
    auto itr = hm.begin();
    auto itr2 = hm.begin();
    itr2++;
    // while(itr != hm.end()){
    //     cout << itr->first << " | " << itr->second << endl;
    //     itr++;
    // }
    while(itr2 != hm.end()){
        res += itr->second;
        itr2->second += itr->second;
        itr++;
        itr2++;
    }
    return res;
}
};