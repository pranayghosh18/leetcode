class Solution {
public:

int validator(vector<vector<int>>& poi, string s, int len){
    unordered_set<char> chr;
    for(int i=0; i<poi.size(); i++){
        // valid
        if(abs(poi[i][0]) <= len && abs(poi[i][1]) <= len){
            if(chr.find(s[i]) != chr.end()) return -1;
            chr.insert(s[i]);
        }
    }
    return chr.size();
}
int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l(0), h(1e9), res(0);
    while(l<=h){
        int m = l +(h-l)/2;
        int r = validator(points, s, m);
        if(r == -1){
            h=m-1; 
        }
        // if(r > 0){
        //     res = r;
        //     l = m+1;
        // }
        else{
            // h = m-1;
            res = r;
            l = m+1;
        }
    }
    return res;
    // set<int, greater<int>> ulens;
    // for(auto p: points){
    //     int mx = max(abs(p[0]), abs(p[1]));
    //     ulens.insert(mx);
    // }
    // for(auto it : ulens){
    //     int re = validator(points, s, it );
    //     if(re > 0) return re;
    // }
    // return 0;
}
};