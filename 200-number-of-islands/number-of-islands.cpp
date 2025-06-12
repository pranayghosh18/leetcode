class Solution {
public:
void groupIt(vector<vector<char>>& grid, int i, int j){
    queue<pair<int,int>> bfs;
    bfs.push({i,j});
    grid[i][j] = '0';

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!bfs.empty()){
        pair<int,int> tp = bfs.front();
        bfs.pop();
        int x = tp.first;
        int y = tp.second;
        for(auto d : dirs){
            int next_x = x + d[0];
            int next_y = y + d[1];

            if(next_x >= 0 && next_x < grid.size() 
            && next_y >= 0 && next_y < grid[0].size()
            && grid[next_x][next_y] == '1'){
                grid[next_x][next_y] = '0';
                bfs.push({next_x, next_y});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int components(0);
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == '1'){
                components++;
                groupIt(grid, i, j);
            }
        }
    }
    return components;
}
};