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

#define elif else if
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int x) {
        vector<ll> ddp(x+1,0);
        ddp[0] = 1;
        rep(i,1,x+1){
            fa(j,nums){
                if(j<=i && i-j >=0) {
                    ddp[i] += ddp[i-j];
                    if(ddp[i] >= INT_MAX) ddp[i] %= MOD;
                }
            }
        }
        rr ddp[x];
    }
};




