class Solution {
public:
    int lengthOfLastWord(string s) {
        int len(0), lastLen(0);
        for(char c : s) c==' ' ? (lastLen = len!=0 ? len : lastLen), len=0 : len++;
        // " vusdn kdlfm sgjkjk" this case
        lastLen = len!=0 ? len : lastLen;
        return lastLen;
    }
};