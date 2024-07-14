class Solution {
public:
//int Target;
// return min cost
vector<vector<int>> dp_2742;
int util_2742(int index, int totalCost, int activeTime, int remaining, vector<int>& cost, vector<int>& time){
    // base
    int requiredTime = remaining - activeTime;
    if(requiredTime <= 0) return 0;
    // cant go further
    // if(index == -1) return 1e9;
    if(index == cost.size()) return 1e9;
    // dp
    if(dp_2742[index][requiredTime] != -1) return dp_2742[index][requiredTime];
    // take 
    int updatedCost = totalCost + cost[index];
    int timeFilled = activeTime + time[index];
    int taken = cost[index] + util_2742(index+1, updatedCost, timeFilled, remaining-1, cost, time);
    // or dont
    int notTaken = util_2742(index+1, totalCost, activeTime, remaining, cost, time);

    return dp_2742[index][requiredTime] = min(taken, notTaken);
}
int tpaintWalls(vector<int>& cost, vector<int>& time) {
    // have to achieve this value
    // Target = (cost.size()+1)/2;
    dp_2742.resize(cost.size()+1, vector<int>(cost.size()+1, -1));
    // return util_2742(cost.size()-1, 0, 0,cost.size(), cost, time);
    return util_2742(0, 0, 0, cost.size(), cost, time);
}
// TLE
vector<vector<int>> dp_2742b;
int util_2742b(int index, int timeDone, vector<int>& cost, vector<int>& time){
    // base
    if(timeDone >= cost.size()) return 0;
    // cant go further
    if(index == -1) return 1e9;
    // dp
    if(dp_2742b[index][timeDone] != -1) return dp_2742b[index][timeDone];
    // take 
    int taken = cost[index] + util_2742b(index-1, timeDone + time[index] + 1, cost, time);
    // or dont
    int notTaken = util_2742b(index-1, timeDone, cost, time);

    return dp_2742b[index][timeDone] = min(taken, notTaken);
}
int vpaintWalls(vector<int>& cost, vector<int>& time) {
    dp_2742b.resize(cost.size()+1, vector<int>(1000000, -1));
    return util_2742b(cost.size()-1, 0, cost, time);
}
vector<vector<int>> dp_2742be;
int util_2742be(int index, int timeReq, vector<int>& cost, vector<int>& time){
    // base
    if(timeReq <= 0) return 0;
    // cant go further
    if(index == -1) return 1e9;
    // dp
    if(dp_2742be[index][timeReq] != -1) return dp_2742be[index][timeReq];
    // take 
    int taken = cost[index] + util_2742be(index-1, timeReq - time[index] - 1, cost, time);
    // or dont
    int notTaken = util_2742be(index-1, timeReq, cost, time);

    return dp_2742be[index][timeReq] = min(taken, notTaken);
}
int paintWalls(vector<int>& cost, vector<int>& time) {
    // have to achieve this value
    // Target = (cost.size()+1)/2;
    dp_2742be.resize(cost.size()+1, vector<int>(cost.size()+1, -1));
    return util_2742be(cost.size()-1, cost.size(), cost, time);
}
};