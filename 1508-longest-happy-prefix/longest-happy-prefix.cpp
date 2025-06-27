class Solution {
public:
string longestPrefix(string s) {
    vector<int> lps(s.size(), 0);
    int matchedLen(0), i(1);
    while (i<s.size())
    {
        if(s[i] == s[matchedLen]){
            matchedLen++;
            lps[i] = matchedLen;
            i++;
        }
        else{
           if(matchedLen > 0) {
            int portionFromMatchedLen = lps[matchedLen-1];
             matchedLen = portionFromMatchedLen;
        }
           else i++;
        }
    }
    int finalMatchedLength = lps.back();
    return s.substr(0, finalMatchedLength);
}
};