class Solution {
public:

void generateParenthesisDfs(int open, int close, string formed, vector<string>&res){
    // base
    if(close == 0 && open == 0) res.push_back(formed);
    // use open and close brackets in organised way
    // smart calling
    if(open > 0) generateParenthesisDfs(open-1, close, formed + string(1, '('), res);
    if(close > open) generateParenthesisDfs(open, close-1, formed + string(1, ')'), res);
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generateParenthesisDfs(n, n, "", ans);
    return ans;
}
};