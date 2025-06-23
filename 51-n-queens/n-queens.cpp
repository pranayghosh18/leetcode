class Solution {
public:
vector<vector<string>> queens_board;
bool validBoard(vector<vector<string>>& board){
    // check horizontally and vertically
    unordered_set<int> rowQueens, colQueens;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == "Q"){
                if(rowQueens.find(i) != rowQueens.end()
                || colQueens.find(j) != colQueens.end()) return false;

                rowQueens.insert(i);
                colQueens.insert(j);
            }
        }
    }

    // check principal diagonal
    unordered_set<int> principalDiagonals;
    for(int pd=0; pd <= (board.size()-1)*2; pd++){
        for(int i=0; i<board.size(); i++){
            int j = pd-i;
            if(j >= 0 && j < board[0].size() && board[i][j] == "Q"){
                if(principalDiagonals.find(pd) != principalDiagonals.end()) return false;
                principalDiagonals.insert(pd);
            }
        }
    }
    
    // check non principal diagonal
    // cout << " test \n " << -(board.size()-1) << endl;
    // int xyz = board.size() - 1;
    // cout << "xyz " << -xyz << endl;
    unordered_set<int> nonPrincipalDiagonals;
    for(int npd = -(int)(board.size() - 1); npd <= (int)(board.size() - 1); npd++){
        cout << "npd " << npd << endl;
        for(int i=0; i<board.size(); i++){
            int j = npd+i;
            if(j >= 0 && j < board[0].size()  && board[i][j] == "Q"){
                cout << "i " << i << " j " << j << endl;
                if(nonPrincipalDiagonals.find(npd) != nonPrincipalDiagonals.end()) return false;
                nonPrincipalDiagonals.insert(npd);
            }
        }
    }

    return true;
}

void dfs(int n, int row, vector<vector<string>> board) {
    if(row == n) {
        // get the foramt
        vector<string> currentBoard;
        for(auto r : board){
            string rowLine;
            for(auto c : r) rowLine += c;
            currentBoard.push_back(rowLine);
        }
        queens_board.push_back(currentBoard);
        return;
    }
    for(int col=0; col<n; col++){
        board[row][col] = "Q";
        if(validBoard(board)) dfs(n, row+1, board);
        board[row][col] = ".";
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> board(n, vector<string>(n, "."));
    dfs(n, 0, board);
    return queens_board;
}
};