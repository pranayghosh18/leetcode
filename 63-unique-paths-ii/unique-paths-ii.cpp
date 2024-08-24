#define intt long long 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& gri) {
        
        if(gri[gri.size()-1][gri[0].size()-1]==1) return 0;
        /*
        int m=INT_MIN+10;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
                {
                    if(grid[i][j]==1) grid[i][j]=m;
                }
        }
        */
        vector<vector<intt>> grid (gri.size(),vector<intt>(gri[0].size(),0));
        
        for(int i = grid.size()-1; i>=0 ; i--)
        {
            for(int j = grid[0].size()-1; j>=0; j--)
                {
                    grid[i][j] = gri[i][j];
                }
        }
        
        for(int i = grid.size()-1; i>=0 ; i--)
        {
            for(int j = grid[0].size()-1; j>=0; j--)
                {
                    if(grid[i][j] == 1) grid[i][j]=0;
                    else if(j == grid[0].size()-1 && i==grid.size()-1)
                        {
                            grid[i][j] = 1;
                        }
                    else if(j == grid[0].size()-1)
                        {
                            grid[i][j] = grid[i+1][j] == 1 ? 1:0;
                        }
                    else if(i == grid.size()-1)
                        {
                            grid[i][j] = grid[i][j+1] == 1 ? 1:0;
                        }
                    else
                        {
                            grid[i][j] = grid[i+1][j] + grid[i][j+1];
                        }
                }
        }
        return grid[0][0];
    }
};