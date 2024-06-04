class Solution {
public:
int mod = 1e9+7;
int getArea(int delX, map<int,int>line){
    int preV(0), preK(-1);
    long long delY(0);
    for(auto it: line){
        if(preV > 0) delY += it.first-preK;
        preK = it.first;
        preV += it.second;
    }
    long long area = ((long long)delX * (delY % mod)) %mod;
    return area;
}

int rectangleArea(vector<vector<int>>& rectangles) {
    // x, signal, y_down, y_up
    vector<vector<int>>rec;
    for(auto r : rectangles) rec.push_back({r[0], 1, r[1], r[3]}), rec.push_back({r[2], 0, r[1], r[3]});
    sort(rec.begin(), rec.end(), [](vector<int>&a, vector<int>&b){ return a[0] < b[0]; });
    int prevX(-1);
    int area(0);
    map<int,int> line;
    for(int i=0; i<rec.size();){
        if(prevX != -1){
            area += getArea(rec[i][0] - prevX, line); 
            area %= mod;
        }
        int j=i;
        while(j<rec.size() && rec[i][0] == rec[j][0]){
            // starting
            if(rec[j][1] == 1) line[rec[j][2]]++, line[rec[j][3]]--;
            if(rec[j][1] == 0) line[rec[j][2]]--, line[rec[j][3]]++; 
            j++;
        }
        prevX = rec[i][0];
        i=j; 
    }
    return area;
}
};