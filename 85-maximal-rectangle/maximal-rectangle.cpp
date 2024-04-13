#define vi vector<int>
#define vvi vector<vector<int>>
#define si stack<int>
class Solution {
    
    vi nsl(vi v){
    si s;
    vi res;
    int pi=-1;
    for(int i=0; i<v.size(); i++){
        if(s.empty()) res.push_back(pi);
        else if(v[i]>v[s.top()]) res.push_back(s.top());
        else{
            while(!s.empty() && v[i]<=v[s.top()]) s.pop();
            if(s.empty()) res.push_back(pi);
            else res.push_back(s.top());
            }
            s.push(i);
        }
        return res;
    }

    vi nsr(vi v){
        si s;
        vi res;
        int pi=v.size();
        for(int i=v.size()-1; i>=0; i-- ){
            if(s.empty()) res.push_back(pi);
            else if(v[i]>v[s.top()]) res.push_back(s.top());
            else{
                while(!s.empty() && v[i]<=v[s.top()]) s.pop();
                if(s.empty()) res.push_back(pi);
                else res.push_back(s.top());
                }
                s.push(i);
            }
        reverse(res.begin(),res.end());
        return res;
    }
    
    int lah(vector<int>& v) {
        
        vi l = nsl(v);
        vi r = nsr(v);
        int ans(0);
        for(int i=0; i<r.size(); i++){
            ans = max(ans,(r[i]-l[i]-1)*v[i]);
        }
        return ans;
    }


public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.size()==0) return 0;
        vi base(mat[0].size());
        for(int j=0; j<mat[0].size(); j++){
                base[j] = mat[0][j]-'0';
        }
    
        int ans(-10);
        ans = max(ans,lah(base));
        
        for(int i=1; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                base[j] = (mat[i][j]-'0')==0 ? 0 : base[j]+1;
            }  
            ans = max(ans,lah(base));
        }
    return ans;
    }
};