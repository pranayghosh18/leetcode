class Solution {
public:
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int i(0);
    for(int e : arr2){
        // get the appropriate pos and swap
        int j=i;
        while(j<arr1.size()){
            if(arr1[j] == e){
                swap(arr1[i], arr1[j]);
                i++;
            }
            j++;
        }
    } 
    sort(arr1.begin()+i, arr1.end());
    return arr1;       
}
};