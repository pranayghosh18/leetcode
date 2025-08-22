class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
    int top(-1), down(-1), left(-1), right(-1);

    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == 1){
                if(top == -1) top = i;
                if(left == -1) left = j;
                if(down == -1) top = i;
                if(right == -1) left = j;

                top = min(i, top);
                left = min(j, left);
                down = max(i, down);
                right = max(j, right);
            }
        }
    }     
    int w = right-left+1;
    int h = down-top+1;

    return h*w;   
}
};