class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
            // create graph
    vector<unordered_map<int,double>> adj(n);
    //vector<pair<int,double>> adj(n);
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].insert( { edges[i][1], succProb[i] } );
        adj[edges[i][1]].insert( { edges[i][0], succProb[i] } );
    }
    // run bfs
    vector<double> probValue(n,0.0);
    probValue[start] = 1.0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        cout<<q.size()<<endl;

        int t = q.front();
        cout << "Adj size " << adj[t].size() << "\n";
        q.pop();
        
        // take the top and push its adjacents and delete the edges : cycle
        // while(adj[t].size() > 0){
        //     auto itr = adj[t].begin();
        //     int adjNode = itr->first;
        //     double prob = itr->second;
        //     // q.push(adjNode);
        //     probValue[adjNode] = max(probValue[adjNode], probValue[t]*prob);
        //     if(probValue[adjNode] ==  probValue[t]*prob) q.push(adjNode);
        //     adj[t].erase(adjNode);
        // }
        
         for(auto it : adj[t]){
// cout << "Aaaaaaaa \n";
             int adjNode = it.first;
             double prob = it.second;
// cout <<"Bbbbbbbb \n";
             //q.push(adjNode);
             double newProb = probValue[t] * prob;
             //probValue[adjNode] = max(probValue[adjNode], probValue[t]*prob);
             //if(probValue[adjNode] ==  probValue[t]*prob) q.push(adjNode);
             if(newProb > probValue[adjNode]){
                 probValue[adjNode] = newProb;
                 q.push(adjNode);
             }
// cout << "Cccccccc \n";
             //adj[t].erase(adjNode);
// cout << "zzzzzzzzz \n";
//cout<<q.size()<<endl;
        }
    }
    return probValue[end];
    }
};