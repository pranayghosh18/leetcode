class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // testing...........
        // cout<<nums.size()<<endl;
    //    for(int i : nums) cout << i <<endl;
    //    if(nums.size() > 5000 ) return {};
        // done
        for(int i=0; i<nums.size();){
        if(nums[i]==nums[ nums[i]-1 ] ) i++;
        else
            swap( nums[i], nums[nums[i]-1] );
    }
    vector<int> res;
        // cout<<"-------\n";
    for(int i=0; i<nums.size(); i++) if(nums[i] != i+1) res.push_back(nums[i]);
    sort(res.begin(),res.end());
    // for(int i : res) cout << i <<endl;
    return res;
    }
};