#define pii pair<int,int>
#define db double
#define ll long long

#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define um unordered_map
#define us unordered_set

#define qi queue<int>
#define sz size()
#define em empty()
#define fr front()
#define po pop()
#define pu push
#define in insert

#define ff first
#define ss second
#define rr return 

#define rep(i,b,e) for(int i=b; i<e; i++)
#define fa(i,v) for(auto& i : v)

#define xsort(v) sort(v.begin(),v.end())
#define elif else if
#define MOD 1000000007

class Solution {
public:
    ll res;
    void dfs(){}
    int numDecodings(string s) {
        vi ddp(s.sz,0);
        if(s[0]=='0') rr 0;
        ddp[0]=1;
        if(s.sz==1) return ddp[0];
        
        string frst2 = s.substr(0,2);
        if(s[1]=='0'){
            ddp[1] = frst2 <= "26" ? 1 : 0;
        }
        else{
            ddp[1] = frst2 <= "26" ? 2 : 1;
        }
        rep(i,2,s.sz){
            string chunk = s.substr(i-1,2);
            if(s[i]=='0'){
                //if(s[i-1]=='0') ddp[i] = 0;
                //else
                    ddp[i] = s[i-1] != '0' && chunk <= "26" ? ddp[i-2] : 0;
            }
            else{
                // if(s[i-1]=='0') ddp[i] = ddp[i-1];
                // else
                    ddp[i] = s[i-1] != '0' && chunk <= "26" ? ddp[i-2]+ddp[i-1] : ddp[i-1];
            }
        }
        return ddp[s.sz-1];
    }
};



