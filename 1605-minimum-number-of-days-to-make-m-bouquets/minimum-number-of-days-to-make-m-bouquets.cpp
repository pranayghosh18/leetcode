class Solution {
public:
bool scheme_1482(vector<int>& bloomDay, int m, int k, int days){
    int flowers(0), bouquets(0);
    for(auto b : bloomDay){
        if( b > days ) flowers=0;
        else{
            bouquets += (flowers+1) / k;
            flowers = (flowers+1) % k;
            if(bouquets >= m) return true;
        }
    }
    return false;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    // Return the minimum number of days you need to wait 
    // monotonicity
    // min k template
    int l(-1),h(-1e5),mid;
    // at min, have enough day to bloom the flower
    for(auto b : bloomDay){
        //l = min(l,b);
        h = max(h,b);
    }
    while( l<h ){
        mid = l +(h-l)/2;
        // the true condition to be executed
        // ie, m also still a potential candidate and so can't discard m
        // but looking for min val so HIGH = MID
        //std::cout<<"low : "<< l << " mid : "<< mid << " high : "<< h <<endl;
        if( scheme_1482(bloomDay,m,k,mid) ) h = mid;
        else
            l = mid+1;
        }
        return scheme_1482(bloomDay,m,k,l) ? l : -1;
}
};