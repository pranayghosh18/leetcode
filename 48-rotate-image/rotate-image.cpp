class Solution {
public:
void flipHorizonatally(vector<vector<int>>& matrix) {
    for(int i=0; i<matrix.size()/2; i++){
        int upper = i;
        int lower = matrix.size() - 1 - i;
        for(int j=0; j<matrix[0].size(); j++){
            swap(matrix[upper][j], matrix[lower][j]);
        }
    }
}

void transpose(vector<vector<int>>& matrix) {
    for(int i=0; i<matrix.size(); i++){
        for(int j=i+1; j<matrix.size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    flipHorizonatally(matrix);
    transpose(matrix);
}
};