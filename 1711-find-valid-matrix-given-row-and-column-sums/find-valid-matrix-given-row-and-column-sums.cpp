class Solution {
public:
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int row(0), col(0);
    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>> matrix(n, vector<int>(m,0));

    while(row<n && col<m){
        int minVal = min(rowSum[row], colSum[col]);
        if(minVal == rowSum[row]){
            matrix[row][col] = minVal;
            for(int j=col+1; j<m; j++) matrix[row][j] = 0; 
        }
        if(minVal == colSum[col]){
            matrix[row][col] = minVal;
            for(int i=row+1; i<n; i++) matrix[i][col] = 0;
        }

        rowSum[row] -= minVal;
        colSum[col] -= minVal;

        if(rowSum[row] == 0) row++;
        if(colSum[col] == 0) col++;
    }

    return matrix;
}
};