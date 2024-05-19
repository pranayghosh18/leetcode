class Solution {
public:
void printGrid(vector<vector<int>> g){
    for(auto v : g){
        for(auto i:v) cout << i << "\t";      
        cout << endl;
    }
}
// [[1,2,1],[1,2,2],[1,2,3]]
// sort based on x-axis ascending
// descending on y-axis if up signal, ascending on y-axis if down signal
// x and y same for a up and down line; up gets priority
bool static comapreSkyline(vector<int>&a, vector<int>&b){
    // if(a[0] == b[0] && a[1] == b[1]){
    //     if(a[2] == b[2] && a[2] == 1) return a[2] > b[2];
    //     if(a[2] == b[2] && a[2] == -1) return a[2] < b[2];
    //     return a[2] > b[2];
    // }

    if(a[0] == b[0]) {
        if(a[2] != b[2]) return a[2] > b[2];
        if(a[2] == b[2] && a[2] == 1) return a[1] > b[1];
        if(a[2] == b[2] && a[2] == -1) return a[1] < b[1];
        // one up and one down then up gets priority if y equal
        // if(a[1] == b[1]) return a[2] > b[2];
        // return a[1]>b[1]; 
    }

    return a[0] < b[0];
}
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // x y state        
    vector<vector<int>> ylines;
    for(auto v : buildings){
        ylines.push_back({v[0], v[2], 1});
        ylines.push_back({v[1], v[2], -1});
    }
    // sort
    // sort(ylines.begin(), ylines.end(), [](vector<int>&a, vector<int>&b){
    //     if(a[0] == b[0] && a[1]==b[1]) return a[2]>b[2];    // start : 1, end : -1
    //     if(a[0] == b[0]) return a[1]>b[1];                  // bigger y first
    //     return a[0] < b[0];                                 // asce x cord
    // });
    sort(ylines.begin(), ylines.end(), comapreSkyline);
    // printGrid(ylines);
    // trace
    int prevHeight(0), curHeight;
    vector<vector<int>> skylines;
    // priority_queue<int> maxHeap;
    multiset<int, greater<int>> maxHeap;
    for(auto l : ylines){
        if(l[2] == 1) maxHeap.insert(l[1]);
        if(l[2] == -1) {
            auto loc = maxHeap.find(l[1]);
            maxHeap.erase(loc);
        }
        // get the max y line in this x cord
        if(!maxHeap.empty()) {
            curHeight = *maxHeap.begin();
        }
        else{
            curHeight = 0;
        }

        if(curHeight != prevHeight) {
                skylines.push_back({l[0], curHeight});
                prevHeight = curHeight;
            }
    }

    return skylines;
}
};