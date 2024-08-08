class Solution {
public:
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int dir(0);
    int move(1);
    vector<vector<int>> res;
    res.push_back({rStart, cStart});
    int hit(1);
    while (hit < rows*cols)
    {
        // right
        // cout << "right \n";
        for(int i=1; i<=move; i++){
            cStart++;
            // cout <<"row : " << rStart << "  col : " << cStart << endl;
            if(0 <= cStart && cStart < cols && 0 <= rStart && rStart < rows) res.push_back({rStart, cStart}), hit++;
        }
        // down
        // cout << "down \n";
        for(int i=1; i<=move; i++){
            rStart++;
            // cout <<"row : " << rStart << "  col : " << cStart << endl;
            if(0 <= cStart && cStart < cols && 0 <= rStart && rStart < rows) res.push_back({rStart, cStart}), hit++;
        }
        // if(rStart >= rows && cStart >= cols) break;
        move++;
        // left
        // cout << "left \n";
        for(int i=1; i<=move; i++){
            cStart--;
            // cout <<"row : " << rStart << "  col : " << cStart << endl;
            if(0 <= cStart && cStart < cols && 0 <= rStart && rStart < rows) res.push_back({rStart, cStart}), hit++;
        }
        // up
        // cout << "up \n";
        for(int i=1; i<=move; i++){
            rStart--;
            // cout <<"row : " << rStart << "  col : " << cStart << endl;
            if(0 <= cStart && cStart < cols && 0 <= rStart && rStart < rows) res.push_back({rStart, cStart}), hit++;
        }
        move++;
    }

    return res;
}
};