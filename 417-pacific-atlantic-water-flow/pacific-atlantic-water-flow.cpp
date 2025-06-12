class Solution {
public:

void fillUpFlow(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& possible) {
    if(possible[x][y]) return;
    possible[x][y] = true;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(auto d : dirs){
            int next_x = x + d[0];
            int next_y = y + d[1];

            if(next_x >= 0 && next_x < heights.size() 
            && next_y >= 0 && next_y < heights[0].size()
            && heights[next_x][next_y] >= heights[x][y]) fillUpFlow(heights, next_x, next_y, possible);
        }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> pasific(heights.size(), vector<bool>(heights[0].size(), false));

    // top and right pacific
    for(int j=0; j<heights[0].size(); j++) fillUpFlow(heights, 0, j, pasific);
    for(int i=0; i<heights.size(); i++) fillUpFlow(heights, i, 0, pasific);

    // bottom and left atlantic
    for(int j=0; j<heights[0].size(); j++) fillUpFlow(heights, heights.size()-1, j, atlantic);
    for(int i=0; i<heights.size(); i++) fillUpFlow(heights, i, heights[0].size()-1, atlantic);

    vector<vector<int>> res;
    for(int i=0; i<heights.size(); i++){
        for(int j=0; j<heights[0].size(); j++){
            if(pasific[i][j] && atlantic[i][j]) res.push_back({i,j});
        }
    }
    return res;
}
};