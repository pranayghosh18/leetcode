class Solution {
public:
int numDecodings(string s) {
    if(s[0] == '0') return 0;
    vector<int> dp(s.size(), 0);
    dp[0] = 1;
    for(int i=1; i<s.size(); i++){
        string lastTwos = s.substr(i-1, 2);
        // if(lastTwos >= "26") return 0;
        // validity
        if(s[i-1] > '0' && lastTwos <= "26") {
            // dp[i] += 1;
            if(i-2 >= 0) dp[i] += dp[i-2];
            else dp[i] += 1;
        }
        if(s[i] != '0') dp[i] += dp[i-1];
    }
    return dp.back();
}
};