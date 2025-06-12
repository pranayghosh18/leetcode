class Solution {
public:
int uniquePaths(int m, int n) {
    vector<vector<int>> ddp(m, vector<int>(n, 0));
    ddp.back().back() = 1;
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i == m-1 || j == n-1) ddp[i][j] = 1;
            else ddp[i][j] = ddp[i+1][j] + ddp[i][j+1];
        }
    }        
    return ddp[0][0];
}
};