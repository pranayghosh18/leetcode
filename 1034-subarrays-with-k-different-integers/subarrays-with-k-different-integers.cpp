#define pii pair<int,int>
#define db double
#define ll long long
#define st string

#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define um unordered_map
#define us unordered_set
#define minheap priority_queue< int, vector<int>, greater<int> >
#define maxheap priority_queue< int > 

#define qi queue<int>
#define sz size()
#define em empty()
#define fr front()
#define po pop()
#define tp top()
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

using namespace std;
class Solution {
public:
    // the come and go approach lead to tle
    /*
    int subarraysWithKDistinct(vector<int>& v, int k) {
        ll f(0),r(0),c(0);
        um<ll,ll> hm;
        
        while(r<v.sz && hm.sz<k ) hm[v[r]]++,r++;
        r--;
        while(hm.sz >= k ){
            ///
            if( hm.sz <= k){
                if(hm.sz==k){
                    cout<<"f : "<< f<<"  r : "<<r <<endl;    
                    c++;
                }
                r++;
                if(r<v.sz) hm[v[r]]++;
            }
            //
            if(r==v.sz || hm.sz > k) {
                hm[v[f]]--;
                if(hm[v[f]]==0) hm.erase(v[f]);
                f++;
                // decrease rear
                while(hm.sz >= k){
                    hm[v[r]]--;
                    if(hm[v[r]]==0) hm.erase(v[r]);
                    r--;   
                }
                r++;
                hm[v[r]]++;
            }
            else{
                c++;
                r++;
                if(r<v.sz) hm[ v[r] ]++;
            }
        }
        // the last front
        ///
        while(hm.sz == k){
            hm[v[f]]--;
            if(hm[v[f]] == 0) rr c;
            f++;
            c++;
        }
        ///
        rr c;
    }
    */
    ll sa_max_k_int(vi& v, ll k){
        
        ll f(0),c(0);
        um<ll,ll> hm;
        
        rep(r,0,v.sz){
            hm[v[r]]++;
            // invlids revoved
            while(hm.sz > k) {
                c += r-f;
                hm[v[f]]--;
                if(hm[v[f]]==0) hm.erase(v[f]);
                f++;
            }
        }
        /*
        while(hm.sz >= k) {
            c += v.sz-f;
            hm[v[f]]--;
            if(hm[v[f]]==0) hm.erase(v[f]);
            f++;
            }
        */
        //cout<<"f end up : "<< f << endl;
        ll x = v.sz-f;
        //cout<<"x val : "<<x<<endl;
        ll y = (x%2 == 0) ? x+1: (x+1)/2;
        if(x%2==0)  x /= 2;
        
        //cout<<"x val : "<<x<<endl;
        //cout<<"y val : "<<y <<endl;
        c += (x*y);
        rr c;
    }
    int subarraysWithKDistinct(vector<int>& v, int k) {
        rr sa_max_k_int(v,k) - sa_max_k_int(v,k-1);
    }
};







