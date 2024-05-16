class NumArray {
public:
    vector<int> sum;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        // this->nums = nums;
        arr.resize(nums.size(), 0);
        sum.resize(nums.size()+1, 0);
        for(int i=0; i<arr.size(); i++) update(i, nums[i]);

        print(arr);
        print(sum);
    }

    void print(vector<int> v){
        for(int i : v) cout << i << "\t";
        cout<< endl;
    }

    int query(int i) {
        int ans(0);
        while(i>0){
            ans += sum[i];
            i -= (i & -i);  // resetting last set bit
        }
        return ans;
    }

    void update(int index, int val) {
        int prevVal = arr[index];
        arr[index] = val;
        int del = val - prevVal;
        int sumIndex = index+1;

        while (sumIndex <= arr.size())
        {
            // cout << "sumIndex : " << sumIndex << "  val : " << sum[sumIndex] << endl;
            sum[sumIndex] += del;
            sumIndex += (sumIndex & -sumIndex); // shifting sumIndex last set bit  
        }
    }

    void build() {
        
    }

    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */