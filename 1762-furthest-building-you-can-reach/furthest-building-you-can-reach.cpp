class Solution {
public:
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> maxLJumps;  
    long long totalJumps(0), maxLJumpsVal(0);
    for(int i=1; i<heights.size(); i++){
        int jump = heights[i] - heights[i-1];
        totalJumps += (jump>0 ? jump : 0);

        if(jump > 0){
            if(maxLJumps.size() < ladders) {
                maxLJumps.push(jump);
                maxLJumpsVal += (long long)jump;
            }
            else{
                if(maxLJumps.size() > 0 && maxLJumps.top() < jump){
                    int minJump = maxLJumps.top();
                    maxLJumps.pop();
                    maxLJumps.push(jump);
                    maxLJumpsVal -= (long long)minJump;
                    maxLJumpsVal += (long long)jump;
                }
            }

            if(totalJumps - maxLJumpsVal > bricks) return i-1;
        }
    }      
    return heights.size()-1;
}
};