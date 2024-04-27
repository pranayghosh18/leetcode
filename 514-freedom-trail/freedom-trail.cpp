class Solution {
public:
unordered_map<int, vector<int>> dict;
vector<vector<int>> dp_518;
pair<int,int> getPrevNext(int idx, vector<int>& locs){
    if(locs.size()==1) return {locs[0], locs[0]};
    auto next = lower_bound(locs.begin(), locs.end(), idx);
    auto prev = next;
    if(next == locs.begin()){
        prev = locs.end();
    }
    prev--;

    return {*prev, *next};
}

pair<int,int> getClockwiseMove(int idx, vector<int>& locs, int totalSize){
    auto pos = lower_bound(locs.begin(), locs.end(), idx);
    if(pos == locs.end()){
        return {totalSize-idx+1+locs[0], locs[0]};
    }
    return {*pos-idx, *pos};
}

pair<int,int> getAntiClockWiseMove(int idx, vector<int>& locs, int totalSize){
    auto pos = lower_bound(locs.begin(), locs.end(), idx);
    if(pos==locs.begin()){
        return {idx+1+totalSize-locs.back(), locs.back()};
    }
    pos--;
    return {idx-*pos, *pos};
}

int util_514(string& ring, string& key, int r, int k){
    if(k==key.size()) return 0;
    if(dp_518[r][k] != -1) return dp_518[r][k];
    if(key[k] == ring[r]) return 1+util_514(ring, key, r, k+1);

    // pair<int,int> prevAndNextIndex = getPrevNext(r, dict[key[k]]);

    // int clKMoves = abs(r-prevAndNextIndex.first) + util_514(ring, key, prevAndNextIndex.first, k+1);
    // int antiClkMoves = abs(r-prevAndNextIndex.second) + util_514(ring, key, prevAndNextIndex.second, k+1);
    // clock wise
    pair<int,int> clkWise = getClockwiseMove(r, dict[key[k]], ring.size()-1);
    int clkWiseCost = clkWise.first + util_514(ring, key, clkWise.second, k);

    pair<int,int> antiClkWise = getAntiClockWiseMove(r, dict[key[k]], ring.size()-1);
    int antiClkWiseCost = antiClkWise.first + util_514(ring, key, antiClkWise.second, k);

    return dp_518[r][k] = min(clkWiseCost, antiClkWiseCost);

}
int findRotateSteps(string ring, string key) {
    for(int i=0; i<ring.size(); i++) dict[ring[i]].push_back(i);
    dp_518.resize(ring.size() + 1, vector<int>(key.size()+1, -1));

    return util_514(ring, key, 0, 0);
}
};