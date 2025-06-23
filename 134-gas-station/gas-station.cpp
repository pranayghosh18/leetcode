class Solution {
public:

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // start from 0 and check how many extra pertrol on tank
    // if < 0, need a next starting point
    // also store how much lack in petrol 
    // so that can be sumed up from next failed point
    // and calculated with balance of to the real start point
    int extraGas(0), requireGas(0), start(0);
    for(int i=0; i<gas.size(); i++){
        extraGas += (gas[i] - cost[i]);
        if(extraGas < 0){
            requireGas += extraGas;
            extraGas = 0;
            start = i+1;
        }
    }
    return extraGas + requireGas >= 0 ? start : -1;
}
};