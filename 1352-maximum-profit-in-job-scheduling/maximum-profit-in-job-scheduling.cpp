class Solution {
public:
    struct elem{
    int start;
    int finish;
    int profit;
};
bool static comp1235(elem a, elem b){
    return a.finish < b.finish; 
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<elem> arr(startTime.size());
    for(int i=0; i<startTime.size(); i++) arr[i] = elem({startTime[i], endTime[i], profit[i]});
    sort(arr.begin(), arr.end(), comp1235); 

    map<int,int> profitAfterTime;
    profitAfterTime[0] = 0;
    for(elem e : arr){
        int start = e.start;
        int finish = e.finish;
        int profit = e.profit;

        auto profitTill = profitAfterTime.upper_bound(start);
        profitTill--;
        int curProfit = profitTill->second + profit;

        if(curProfit > profitAfterTime.rbegin()->second) profitAfterTime[finish] = curProfit;
    }
    return profitAfterTime.rbegin()->second;
}
};