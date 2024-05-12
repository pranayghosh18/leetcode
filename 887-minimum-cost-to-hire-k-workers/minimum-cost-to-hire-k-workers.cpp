class Solution {
public:
    struct elem857
{
    double ratio;
    int qul;
    int sal;
};

struct compare857
{
    // storing ascending order of ratio in VECTOR
    bool operator()(elem857& a, elem857& b){
       return a.ratio < b.ratio;
    }
};
struct compare857PQ
{
    // storing MAX heap in order of qul
    bool operator()(elem857& a, elem857& b){
        return a.qul < b.qul;
    }
};
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<elem857> rec(quality.size());
    for(int i=0; i<quality.size(); i++){
        elem857 elem({(double)wage[i]/ (double)quality[i], quality[i], wage[i]});
        rec[i] = elem;
    }
    sort(rec.begin(), rec.end(), compare857());

    priority_queue<elem857, vector<elem857>, compare857PQ> maxHeap;
    double res(1e9);
    int heapSum(0);
    for(int i=0; i<rec.size(); i++){
        if(i>=k-1){
            // get sum from maxHeap for (k-1) items
            double payOthers = (double)heapSum * rec[i].ratio; 
            // minimize res
            res = min(res, payOthers+rec[i].sal);
        }
        maxHeap.push(rec[i]);
        heapSum += rec[i].qul;
        if(maxHeap.size() >= k){
            int maxQuality = maxHeap.top().qul;
            heapSum -= maxQuality;
            maxHeap.pop();
        }
    }

    return res;
}
};