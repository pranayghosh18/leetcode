class Solution {
public:
int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    unordered_set<int> rowSums={0};
    int maxPrev(1e9);
    for(int r=mat.size()-1; r>=0; r--){
        unordered_set<int> nextRowSums;
        for(int c : mat[r]){
            int maxInCurrItr(1e9);
            for(auto i : rowSums){
                int s = c+i;
                // if(s > target && s > maxPrev) continue;
                if(s > target) maxInCurrItr = min(maxInCurrItr, s);
                if(s <= maxInCurrItr) nextRowSums.insert(s);
            }
        }
        rowSums = nextRowSums;
    }
    int minDif(1e9), sum;       
    for(int i : rowSums) {
        // cout << i <<"\t";
        int dif = abs(i-target);
        if(minDif > dif){
            sum = i;
            minDif = dif;
        }
    }
    return minDif;
}
};