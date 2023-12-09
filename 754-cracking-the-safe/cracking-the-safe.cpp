class Solution {
public:
    vector<string> getAdjs(string s, int k){
    string pref = s.substr(1,s.size()-1);
    vector<string> adjs;
    for(int i=0; i<k; i++){
        string adj = pref;
        adj.push_back(i+'0');
        adjs.push_back(adj);
    }
    return adjs;
}
string utilDfs_753(string cur, unordered_set<string>& seen, int k, int allPossibles){
    string result;
    // 2. base
    if(seen.size() == allPossibles) return cur;
    // 1. simple recusrion
    vector<string> adjacents = getAdjs(cur, k);
    for(auto v : adjacents){
        if(seen.find(v) == seen.end()){
            seen.insert(v);
            string childStr = utilDfs_753(v, seen, k, allPossibles);
            if(childStr.size() != 0){
                result.push_back(cur[0]);
                result += childStr;
                return result;
            }
            // backtracking
            seen.erase(v);
        }
    }
    return result;
}

string crackSafe(int n, int k) {
    int allPossibles = (int)pow(k,n);
    string initinalKey(n, '0');
    unordered_set<string> seen;
    seen.insert(initinalKey);
    return utilDfs_753(initinalKey, seen, k, allPossibles);
}
};