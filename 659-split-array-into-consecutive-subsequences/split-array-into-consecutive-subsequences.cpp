class Solution {
public:
bool isPossible(vector<int>& nums) {
    unordered_map<int,int> freq;
    unordered_map<int,int> last;        
    for(int i: nums) freq[i]++;
    for(int i : nums){
        if(freq[i] == 0) continue;
        freq[i]--;

        // join exsisting line
        if(last.find(i-1) != last.end() && last[i-1] > 0){
            last[i-1]--;
            last[i]++;
        }
        // create new line
        else{
            // need to take 2 others
            if(freq.find(i+1) == freq.end() || freq[i+1] == 0 ||
                freq.find(i+2) == freq.end() || freq[i+2] == 0) return false;
            freq[i+1]--;
            freq[i+2]--;
            last[i+2]++;
        }
    }
    return true;
}
};