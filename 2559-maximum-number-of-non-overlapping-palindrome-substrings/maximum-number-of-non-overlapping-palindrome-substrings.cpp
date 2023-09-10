class Solution {
public:
    
int maxPalindromes(string s, int k) {
    // create palindrom table
    vector<vector<bool>> panlinTable(s.size(),vector<bool>(s.size(), false));
    for(int wlen=1; wlen<=s.size(); wlen++){
        for(int left=0, right=wlen-left-1; right<s.size(); left++,right++){
            if(wlen==1) panlinTable[left][right]=true;
            else if(wlen==2) panlinTable[left][right]=(s[left]==s[right]);
            else{
                if(s[left]==s[right]) panlinTable[left][right] = panlinTable[left+1][right-1]; 
            }
        }
    }
    // lis
    vector<int>dp(s.size(),0);
    vector<int>maxSeen(s.size(),0);

    for(int i=k-1; i<s.size(); i++){
        for(int j=i-k+1; j>=0; j--){
            // check if slice s[j..i] is palindrome
            bool isSlicePalindrome = panlinTable[j][i];
            if(isSlicePalindrome){
                int maxTill = (j==0) ? 0 : dp[j-1];
                dp[i] = max(dp[i], 1+maxTill);
            }
        }
        if(i > 0 && dp[i] < dp[i-1]) dp[i] = dp[i-1];
    }

    for(int i : dp) cout << i <<"\t";
    return dp.back();
}
};