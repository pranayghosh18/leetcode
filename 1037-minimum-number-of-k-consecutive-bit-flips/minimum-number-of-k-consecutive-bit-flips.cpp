class Solution {
public:
class SegTreePointQueryRangeUpdate{
    vector<int> segTree;
    int segTreeSize;
    
    void add(int idx, int value){
        idx++;
        while (idx < segTreeSize)
        {
            segTree[idx] += value;
            idx += (idx & -idx);
        }
    }

public:
    SegTreePointQueryRangeUpdate(int size){
        segTreeSize = size+1;
        segTree.resize(segTreeSize, 0);
    }

    void addRange(int l, int r, int value){
        if(l <= r){
            add(l, value);
            add(r+1, -value);
        }
    }

    int getValue(int idx){
        idx++;
        int sum(0);
        while (idx > 0)
        {
            sum += segTree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};

/*
LC 995

0 1 2 3 4 5 6 7  N = 8
0,0,0,1,0,1,1,0 ; k=3
1 1 1, 1 0 1 1 0 [1]
1 1 1 1, 0 1 1 0 
1 1 1 1 1, 0 0 0 [1]
1 1 1 1 1 1 1 1  [1]
*/

int minKBitFlips(vector<int>& nums, int k) {
    int flips(0);
    SegTreePointQueryRangeUpdate segT(nums.size());

    for(int i=0; i<nums.size()-k+1; i++){
        int prevFlips = segT.getValue(i);
        int ones = nums[i] + prevFlips; 
        // flip from i th to (i+k-1) th bit
        if(!(ones & 1)){
            flips++;
            int left = i+1;
            int right = i+k-1;
            segT.addRange(left, right, 1);
        }
    }
    
    // for the remaining
    for(int i=nums.size()-k+1; i<nums.size(); i++){
        int prevFlips = segT.getValue(i);
        int ones = nums[i] + prevFlips;
        if(!(ones & 1)) return -1;
    }

    return flips;
}
};