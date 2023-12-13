class Solution {
public:
int numSpecial(vector<vector<int>>& mat) {
    int res(0);
    vector<int> rows(mat[0].size(),0);
    vector<int> cols(mat.size(),0);
    // fill up 
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            rows[j] += mat[i][j];
            cols[i] += mat[i][j];
        }
    }
    for(int c=0; c<mat[0].size(); c++){
        int colOnes(0);
        for(int r=0; r<mat.size(); r++){
            if(mat[r][c] == 1 && rows[c] == 1 && cols[r] == 1) res++;
        }
    }        
    return res;
}
};