class Solution {
public:
    
int getCount_1287(vector<int>& arr, int elem){
    auto lb = lower_bound(arr.begin(), arr.end(), elem);
    auto ub = upper_bound(arr.begin(), arr.end(), elem);
    cout << elem << " diff " << ub-lb << endl;
    return (ub-lb);
}
int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    vector<int> candidateIndexes = {n/4, n/2, 3*n/4};         
    for(int candidateIndex :candidateIndexes) if(getCount_1287(arr, arr[candidateIndex]) > n/4) return arr[candidateIndex];
    return -1;
}
};