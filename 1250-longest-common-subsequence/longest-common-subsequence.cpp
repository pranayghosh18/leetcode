class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> ddp(text1.size()+1, vector<int>(text2.size()+1, 0));
    int res(0);
    for(int r=text1.size()-1; r>=0; r--){
        for(int c=text2.size()-1; c>=0; c--){
            ddp[r][c] =  text1[r] == text2[c] ? 1 + ddp[r+1][c+1] : max(ddp[r+1][c], ddp[r][c+1]);
            res = max(res, ddp[r][c]);
        }
    }
    return res;
}
};