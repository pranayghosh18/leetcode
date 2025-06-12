class Solution {
public:
    
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> possible(s.size(), false);
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    for(int i=0; i<s.size(); i++){
        for(int j=i; j>=0; j--){
            string slice = s.substr(j, i-j+1);
            if(words.find(slice) != words.end()) possible[i] = j==0? true : (possible[i] || possible[j-1]);
        }
    }    
    return possible.back();    
}
};