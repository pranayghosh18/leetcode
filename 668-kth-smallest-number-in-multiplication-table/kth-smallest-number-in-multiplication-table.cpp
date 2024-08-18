class Solution {
public:
bool scheme_668( int m, int n, int k, int elem ){
    int count(0);   // count tracks total no of elems <= elem, in (m*n) table
    for(int row=1; row<=m; row++){
        count += min(n, elem/row); // at rth row no of elem <= elem == elem/r, but right boundry is n
        if(count >= k) return true;
    }
    return false; 
}
int findKthNumber(int m, int n, int k) {
    int l(1), h(m*n), mid;
    while (l<h)
    {
        mid = l + (h-l)/2;
        /* true condition */
        if( scheme_668(m,n,k,mid) ) h=mid;    // m is still a probable candidate
        else
            l = mid+1;
    }
    return l;
}
};