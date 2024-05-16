class NumArray {
private:
    void build() {
        for(int i=0; i<arr.size(); i++){
            int fwtIdx = i+1;
            while (fwtIdx <= arr.size())
            {
                sum[fwtIdx] += arr[i];
                fwtIdx += (fwtIdx & -fwtIdx); // shifting sumIndex last set bit  
            }
        }
    }

    int query(int i) {
        int ans(0);
        while(i>0){
            ans += sum[i];
            i -= (i & -i);  // resetting last set bit
        }
        return ans;
    }

public:
    vector<int> sum;
    vector<int> arr;
    NumArray(vector<int>& arr) {
        this->arr = arr;
        sum.resize(arr.size()+1, 0);
        build();
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