class Solution {
public:
    
bool canFit1160(unordered_map<char,int> availChars, string word){
    for(char c : word){
        if(availChars[c] <= 0) return false;
        availChars[c]--;
    }
    return true;
}
int countCharacters(vector<string>& words, string chars) {
    unordered_map<char,int> availChars;
    for(char c : chars) availChars[c]++;     
    int res(0);
    for(string w : words) if(canFit1160(availChars, w)) res += w.size();
    return res;   
}
};