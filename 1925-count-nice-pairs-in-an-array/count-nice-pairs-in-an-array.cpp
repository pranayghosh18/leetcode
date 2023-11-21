class Solution {
public:
    
int revInt(int i){
    if(i==0) return 0;
    string s = to_string(i);
    while(s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    // int r = stoi(s);
    //cout << i << " rev " << r << endl;
    return stoi(s);
}
int countNicePairs(vector<int>& nums) {
    unordered_map<int,int> hm;
    for(int i : nums) hm[i-revInt(i)]++;
    int mod = 1e9+7;
    //for(auto it : hm) cout << it.first <<" : " << it.second << endl;
    long res(0);
    for(auto it : hm) res+= ((long)(it.second-1)*(long)(it.second))/2, res%=mod;
    return res;
}
};