class Solution {
public:
    int find_947(int x, unordered_map<int,int>&root){
    if(x==root[x]) return x;
    return root[x] = find_947(root[x], root);
}

void union_947(int u, int v, unordered_map<int,int>& root, unordered_map<int,int>& sizes){
    int par_u = find_947(u, root);
    int par_v = find_947(v, root);

    if(par_u == par_v) return;

    root[par_u] = par_v;
    sizes[par_v] += sizes[par_u];
}

int getParentSize(int u, unordered_map<int,int>& root, unordered_map<int,int>& sizes, unordered_set<int>&seenNode){
    int par_u = find_947(u, root);
    if(seenNode.find(par_u) == seenNode.end()){
        seenNode.insert(par_u);
        return (sizes[par_u]-1);
    }
    return 0;
}
int removeStones(vector<vector<int>>& stones) {
    // create graph
    unordered_map<int,vector<int>> xnodes;
    unordered_map<int,vector<int>> ynodes;
    unordered_map<int,int> root;
    unordered_map<int,int> sizes;
    for(int i=0; i<stones.size(); i++){
        int istone = stones[i][0]*1000+stones[i][1];
            xnodes[stones[i][0]].push_back(istone);
            ynodes[stones[i][1]].push_back(istone);
            root[istone] = istone;
            sizes[istone] = 1;
    }

    // unordered_map<int,vector<int>> adjGraph;
    for(auto itr : xnodes){
        for(int i=0; i<itr.second.size(); i++){
            for(int j=i+1; j<itr.second.size(); j++){
                // adjGraph[itr.second[i]].push_back(itr.second[j]);
                // adjGraph[itr.second[j]].push_back(itr.second[i]);
                union_947(itr.second[i], itr.second[j], root, sizes);
            }
        }
    }
    for(auto itr : ynodes){
        for(int i=0; i<itr.second.size(); i++){
            for(int j=i+1; j<itr.second.size(); j++){
                // adjGraph[itr.second[i]].push_back(itr.second[j]);
                // adjGraph[itr.second[j]].push_back(itr.second[i]);
                union_947(itr.second[i], itr.second[j], root, sizes);
            }
        }
    }

    // get the results
    // for all nodes checking
    int res(0);
    unordered_set<int> seenNodes;
    for(auto itr : xnodes){
        for(int i=0; i<itr.second.size(); i++) res += getParentSize(itr.second[i], root, sizes, seenNodes);
    }
    for(auto itr : ynodes){
        for(int i=0; i<itr.second.size(); i++) res += getParentSize(itr.second[i], root, sizes, seenNodes);
    }

    return res;
}
};