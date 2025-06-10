class Solution {
public:
    
    vector<vector<bool>> seen;
    vector<vector<char>> b;
    string w;
    bool f(int x, int y, int pos)
        {
            //5. base for termination
            if(pos==w.size()) return true;
            //3. all about the base
            //3a. boundary 
            if(x<0 || x>=b.size() || y<0 || y>=b[0].size()) return false;
            //3b. blocking or visiting
            if(seen[x][y]) return false;
            //3c. conditional
            if(b[x][y]!=w[pos]) return false;
        
            //4. backtrack sign 
            //4a. first unavail
            seen[x][y]=true;
            //1. rec call stupid
            if(f(x+1,y,pos+1)) return true;
            if(f(x-1,y,pos+1)) return true;
            if(f(x,y+1,pos+1)) return true;
            if(f(x,y-1,pos+1)) return true;
            //2. all falls down
            //4b. call ends so make avail
            seen[x][y]=false;
            return false;
        }
    bool exist(vector<vector<char>>& board, string word) {
        b=board;
        w=word;
        seen.resize(board.size(), vector<bool>( board[0].size() , false ) );
        //1. find word[0]s
        vector<pair<int,int>> hm;
        for(int i=0; i<b.size(); i++)
            {
                for(int j=0; j<b[0].size(); j++)
                    {
                        if(b[i][j]==w[0]) hm.push_back({i,j});
                    }
            }
        //2. call for each one
        for(auto it: hm)
            {
                if(f(it.first,it.second,0)) return true;
            }
        return false;
    }

};














