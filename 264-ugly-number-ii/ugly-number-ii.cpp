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
    int nthUglyNumber(int n) {
        vi ddp(n,0);
        ddp[0]=1;
        ll a,b,c;
        a=b=c=0;
        rep(i,1,n){
            ddp[i] = min( { ddp[a]*2, ddp[b]*3, ddp[c]*5 } );
            if(ddp[i]==ddp[a]*2) a++;
            if(ddp[i]==ddp[b]*3) b++;
            if(ddp[i]==ddp[c]*5) c++;
        }
        return ddp[n-1];
    }
};