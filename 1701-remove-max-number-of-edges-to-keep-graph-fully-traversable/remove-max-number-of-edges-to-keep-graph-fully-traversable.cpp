class Solution {
public:
class UF{
    vector<int> parent;
    int components;
public:
    UF(int n){
        parent.resize(n);
        components = n;
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int u){
        return u==parent[u] ? u : parent[u] = find(parent[u]);
    }

    // bool isSameComponent(int u, int v){
    //     int par_u = find(u);
    //     int par_v = find(v);

    //     return par_u == par_v;    
    // }

    bool join(int u, int v){
        int par_u = find(u);
        int par_v = find(v);

        if(par_u != par_v) {
            parent[par_u] = par_v;
            components--;
            return true;
            }

        return false;
    }

    int getComponentCount(){
        // unordered_set<int> count;
        // for(int i=0; i<parent.size(); i++) count.insert(find(i));

        // return count.size();
        return components;
    }
};

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    UF aliceVisited(n), bobVisited(n);
    sort(edges.rbegin(), edges.rend());
    cout << edges.size();
    int res(0);
    for(auto e : edges){
        int type = e[0];
        int u = e[1]-1;
        int v = e[2]-1;

        bool isReqByAlice(false), isReqByBob(false);
        // checking for alice
        if(type != 2) isReqByAlice = aliceVisited.join(u, v);
        // checking for bob
        if(type != 1) isReqByBob = bobVisited.join(u,v);

        if(!isReqByAlice && !isReqByBob) res++;
    }
    return (aliceVisited.getComponentCount() == 1 && bobVisited.getComponentCount() == 1) ? res : -1;
}
};