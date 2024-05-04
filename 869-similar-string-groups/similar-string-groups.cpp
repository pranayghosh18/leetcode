class Solution {
public:
    
class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionD(int u, int v){
        int parU = find(u);
        int parV = find(v);

        if(parU != parV) parent[parU] = parV;
    }
};

bool hasConnection(string s, string t){
    if(s == t) return true;
    int x(-1), y(-1), count(0);
    for(int i=0; i<s.size(); i++){
        if(s[i] == t[i]) continue;
        count++;
        if(count > 2) return false;
        if(x == -1) x = i;
        else{
            y = i;
        }
    }

    return (s[x]==t[y] && s[y]==t[x]); 
}
int numSimilarGroups(vector<string>& strs) {
    DSU dsu(strs.size());
    for(int i=0; i<strs.size(); i++){
        for(int j=i+1; j<strs.size(); j++){
            if(hasConnection(strs[i], strs[j])) dsu.unionD(i,j);
        }
    }
    unordered_set<int> nodes;
    for(int i=0; i<strs.size(); i++) {
        cout << dsu.find(i) << "\t";
        nodes.insert(dsu.find(i));
    }

    return nodes.size();
}
};