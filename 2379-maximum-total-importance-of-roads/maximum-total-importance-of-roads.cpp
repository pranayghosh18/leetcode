class Solution {
public:
long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<pair<int,int>> inDegree(n);
    for(int i=0; i<n; i++) inDegree[i].second = i;
    for(auto r : roads){
        inDegree[r[0]].first++;
        inDegree[r[1]].first++;
    }        
    sort(inDegree.begin(), inDegree.end());
    unordered_map<int,int> nodeToVal;
    for(int i=0; i<n; i++){
        nodeToVal[inDegree[i].second] = i+1;
    }
    long long res(0);
    for(auto r : roads) res += (long long)nodeToVal[r[0]], res += (long long)nodeToVal[r[1]];

    return res;
}
};