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
    int longestSubarray(vector<int>& v, int lim) {
        ll f(0),l(0);
        multiset<ll> win;
        rep(r,0,v.sz){
            win.in(v[r]);
            // invalid
            while( *win.rbegin() - *win.begin() > lim){
                auto it = win.find( v[f] );
                win.erase(it);
                f++;
            }
            // valid
            l = max(l, r-f+1);
        }
        rr l;
    }
};





