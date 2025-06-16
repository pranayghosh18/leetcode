#define ll long long
#define rep(i,b,e) for(int i=b; i<e; i++)
class Solution {
public:
    ll simpKadane(vector<int>& v){
        ll r(v[0]);
        ll s(v[0]);
        rep(i,1,v.size()){
            ll e = v[i];
            s = max(e, s+e);
            r = max(r,s);
        }
        return r;
    }
    ll inversionKadane(vector<int>& v){
        ll s(0);
        for(int i : v) s+=i;
        
        for(int &i : v) i*=-1;
        
        ll kad = simpKadane(v);
        
        for(int &i : v) i*=-1;
        
        return s+kad;
    }
    
    ll min_subarray_sum(vector<int>& v){
        int mins(0), sum(0);
        for(int i : v){
            sum = min( sum+i, i);
            mins = min(mins,sum);
        }
        return mins;
    }
    
    int maxSubarraySumCircular(vector<int>& v) {
        //ll ik = inversionKadane(v);
        ll maxSubArrSum = simpKadane(v);
        ll minSubArrSum = min_subarray_sum(v);
        ll total(0);
        for(int i : v) total+=i;
        if(maxSubArrSum < 0) return maxSubArrSum;
        
        return max(maxSubArrSum, total-minSubArrSum);
    }
};