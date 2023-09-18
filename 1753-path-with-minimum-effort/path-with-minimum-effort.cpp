class Solution {
public:
int singleSourceSingleDestSortestPath(int src, int dest, vector<vector<pair<int,int>>>&graph){
    // apply simple dijkstra
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    set<pair<int,int>> minHeap;
    minHeap.insert({0,src});
    unordered_map<int,int> calculatedNodes;
    unordered_set<int> seenNodes;

    while(!minHeap.empty()){
        auto top = minHeap.begin();
        int topNode = top->second;
        int weightTill = top->first;
        if(topNode == dest) return weightTill;
        minHeap.erase(top);
        seenNodes.insert(topNode);
        // for all adj nodes perform
        for(auto it : graph[topNode]){
            int adjNode = it.second;
            int weight = it.first;
            if(seenNodes.find(adjNode) == seenNodes.end()){ 
                // adj node seen first time
                if(calculatedNodes.find(adjNode) == calculatedNodes.end()){
                    int applicableWeight = max(weightTill, weight);
                    minHeap.insert({applicableWeight, adjNode});
                }
                // adj node visited 1+ times
                else{
                    int applicableWeight = max(weightTill, weight);
                    if(applicableWeight < calculatedNodes[adjNode]){
                        // delete exsistance of adjNode from min heap and put new instance
                        int adjNodeWeight = calculatedNodes[adjNode];
                        auto node = minHeap.find({adjNodeWeight,adjNode});
                        minHeap.erase(node);
                        // insert adj node with new weight
                        minHeap.insert({applicableWeight, adjNode});
                        calculatedNodes[adjNode] = applicableWeight;
                    }
                }
            }
        }
    }
    return -1;
}
int minimumEffortPath(vector<vector<int>>& heights) {
    // prepare the graph
    vector<vector<pair<int,int>>> graph(heights.size()*heights[0].size());
    for(int i=0; i<heights.size(); i++){
        for(int j=0; j<heights[0].size(); j++){
            int nodeId = i*(heights[0].size()) + j;
            // left
            if(j!=0){
                int leftNodeId = i*(heights[0].size()) + (j-1);
                int wei = abs(heights[i][j] - heights[i][j-1]);
                graph[nodeId].push_back({wei,leftNodeId});
            }
            // right
            if(j!=heights[0].size()-1){
                int rightNodeId = i*(heights[0].size()) + (j+1);
                int wei = abs(heights[i][j] - heights[i][j+1]);
                graph[nodeId].push_back({wei,rightNodeId});
            }
            // up
            if(i!=0){
                int upNodeId = (i-1)*(heights[0].size()) + j;
                int wei = abs(heights[i][j] - heights[i-1][j]);
                graph[nodeId].push_back({wei,upNodeId});
            }
            // down
            if(i!=heights.size()-1){
                int downNodeId = (i+1)*(heights[0].size()) + j;
                int wei = abs(heights[i][j] - heights[i+1][j]);
                graph[nodeId].push_back({wei,downNodeId});
            }
        }
    }
    
    int targetNodeId = graph.size()-1;
    return singleSourceSingleDestSortestPath(0,targetNodeId,graph);
}
};