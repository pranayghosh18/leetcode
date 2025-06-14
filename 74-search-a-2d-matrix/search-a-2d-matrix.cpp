class Solution {
public:

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i(0), j(matrix[0].size()-1);
    while(i<matrix.size() && j >= 0 && matrix[i][j] != target) matrix[i][j] < target ? i++ : j--;
    return i<matrix.size() && j >= 0 && matrix[i][j] == target;
}
};