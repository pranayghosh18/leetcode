class Solution {
public:
struct compare{
    bool operator() (const pair<int,int>& p, pair<int,int>& q){
        long dist1 = long(p.first)*long(p.first) + long(p.second)*long(p.second);
        long dist2 = long(q.first)*long(q.first) + long(q.second)*long(q.second);
        return dist1 < dist2;
    } 
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> maxHeap;
    for(auto p : points){
        maxHeap.push({p[0], p[1]});
        if(maxHeap.size() > k) maxHeap.pop();
    }
    vector<vector<int>> res;
    while(!maxHeap.empty()){
        pair<int,int> tp = maxHeap.top();
        maxHeap.pop();
        res.push_back({tp.first, tp.second});
    }
    return res;
}
};
