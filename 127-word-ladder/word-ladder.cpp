class Solution {
public:
    // simp dfs/ backtrack ...... tle
    /*
    int ans=INT_MAX;
    vector<bool> u;
    
    bool hd1(string b, string e)
        {
            int i(0),j(0),c(0);
            while(i<b.size()&&j<e.size())
                {
                    if(b[i]!=e[j]){c++;}
                    if(c>1) return false;
                    i++;
                    j++;
                }
            if(c==0) return false;
            return true;
        }
    int hd(string b, string e)
        {
            int i(0),j(0),c(0);
            while(i<b.size()&&j<e.size())
                {
                    if(b[i]!=e[j]){c++;}
                    i++;
                    j++;
                }
            return c;
        }
    void f(string b, string e, vector<string>& w, int coun)
        {
        
            if(b==e)
                {
                    ans = min(ans,coun);
                    return;
                }
            for(int i=0; i<w.size(); i++)
                {
                    if(!u[i])
                        {
                            if(hd1(b,w[i]))
                                {
                                    u[i]=true;
                                    f(w[i],e,w,coun+1);
                                    u[i]=false;
                                }
                        }
                }
        }
    bool ispresent(string e, vector<string>& w)
        {
            for(string s : w)
                {
                    if(s==e) return true;
                }
            return false;
        }
    int ladderLength(string b, string e, vector<string>& w) {
        if(!ispresent(e,w)) return 0;
        u.resize(w.size(),false);
        f(b,e,w,1);
        if(ans==INT_MAX) return 0;
        return ans;
    }
    */
    
    // go with bfs
    bool ispresent(string e, vector<string>& w)
        {
            for(string s : w) if(s==e) return true;
            return false;
        }
    
    bool hd(string b, string e)
        {
            int i(0),j(0),c(0);
            while(i<b.size()&&j<e.size())
                {
                    if(b[i]!=e[j]){c++;}
                    if(c>1) return false;
                    i++;
                    j++;
                }
            if(c==0) return false;
            return true;
        }
    
    int ladderLength(string b, string e, vector<string>& w) {
        
        if(!ispresent(e,w)) return 0;
        // graph creation
        if(!ispresent(b,w)) w.push_back(b);
        
        unordered_map<string,vector<string>> adj;
        unordered_map<string,bool> vis;
        /*
        for(string s : w){
            vis[s] = false;
            for(string t : w){
                if(hd(s,t)) adj[s].push_back(t);
            }
        }
        */
        for(int i=0; i<w.size()-1; i++){
            for(int j=i+1; j<w.size(); j++){
                if(hd(w[i],w[j])){
                    adj[w[i]].push_back(w[j]);
                    adj[w[j]].push_back(w[i]);
                }
            }
        }
        
        // simp bfs
        queue<string> q;
        q.push(b);
        vis[b] = true;
        int dis(1);
        while(!q.empty()){
            int siz = q.size();
            for(int i=0; i<siz; i++){
                string f  = q.front();
                if(f==e) return dis;
                q.pop();
                // add unvisited adjacents
                for(string s : adj[f]){
                    if(!vis[s]){
                        q.push(s);
                        vis[s] = true;
                    }
                }
            }
            dis++;
        }
        /*
        for(auto it : vis){
            if (!it.second) return 0;
        }
       */ 
        return 0;
    }
};