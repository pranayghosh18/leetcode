class Solution {
public:
int decodeWaysDfs(string s, int i, vector<int>& memo){
    // bases
    if(i == s.size()) return 1;
    if(s[i] == '0') return 0;
    if(memo[i] != -1) return memo[i];
    int singleEffect(0), doubleEffect(0);
    singleEffect = decodeWaysDfs(s, i+1, memo);
    if(i+1 < s.size() && stoi(s.substr(i, 2)) <= 26) doubleEffect = decodeWaysDfs(s, i+2, memo);

    return memo[i] = singleEffect+doubleEffect;
}
int numDecodings(string s) {
    vector<int> memo(s.size(), -1);
    return decodeWaysDfs(s, 0, memo);
}
};