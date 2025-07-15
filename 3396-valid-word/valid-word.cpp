class Solution {
public:
    
bool isValid(string word) {
    bool v(false), cns(false);
    if(word.size() < 3) return false;
    unordered_set<char> vow = {'a','e','i','o','u'};
    
    for(char c : word){
        // cout << "-> " << c << "\n";
        if('0' <= c && c <= '9') continue;
        if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')){
            if( vow.find(tolower(c)) != vow.end()) v = true;
            else{
                cns = true; 
            }
        }
        else{
            return false;
        }
    }
    return (v&cns);        
}
};