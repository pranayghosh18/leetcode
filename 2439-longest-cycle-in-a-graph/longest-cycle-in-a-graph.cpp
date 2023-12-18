class Solution {
public:
int bfs_2360(int node, vector<int>& edges, unordered_set<int>& prevItrSeen){
    int level(0);
    int cycle(-1);

    if(prevItrSeen.find(node) != prevItrSeen.end()) return cycle;
    // current itr
    unordered_map<int,int> processedNode;
    queue<int> q;
    q.push(node);
    // seen.insert(node);

    while(!q.empty()){
        int sz = q.size();
        for(int i=1; i<=sz; i++){
            int top = q.front();
            processedNode[top] = level;
            q.pop();
            if(edges[top] != -1){
                // if(!seen[ edges[top] ]){
                //     q.push(edges[top]);
                //     seen.insert(edges[top]);
                // }

                // visited in current iteration
                if(processedNode.find(edges[top]) != processedNode.end()){
                    cycle = max(cycle, level - processedNode[edges[top]] + 1);
                }
                else if(prevItrSeen.find(edges[top]) == prevItrSeen.end()){
                    q.push(edges[top]);
                    // seen.insert(edges[top]);
                    prevItrSeen.insert(edges[top]);
                }
            }
        }
        level++;
    }
    return cycle;
}

int longestCycle(vector<int>& edges) {
    int cycle(-1);    
    unordered_set<int> prevIterSeenNodes;

    for(int i=0; i<edges.size(); i++){
        cycle = max(bfs_2360(i, edges, prevIterSeenNodes), cycle);
        // update prevItrSeenOnes
        // prevIterSeenNodes = seenNodes;
    }
    return cycle;
}

};