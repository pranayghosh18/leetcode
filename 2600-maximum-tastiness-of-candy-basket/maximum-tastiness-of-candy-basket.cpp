class Solution {
public:
bool schema_2517(vector<int>& price, int k, int diff) {
    int count(1), start(price[0]);
    for(int i=1; i<price.size(); i++) {
        if(price[i] - start >= diff) count++, start = price[i];
        if(count >= k) return true;
    }
    return count >= k;
}

int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());
    int l(0), h(price.back() - price.front());
    while(l < h){
        int m = (h+l+1)/2;
        // cout << "h " << h << " m " << m << " l " << l << endl;
        if(schema_2517(price, k, m)) l = m;
        else h = m-1;
    }    
    return l;
}
};