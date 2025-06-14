class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<int> rec;
    for(int i=temperatures.size()-1; i>=0; i--) {
        while(!rec.empty() && temperatures[i] >= temperatures[rec.top()]) rec.pop();
        if(!rec.empty()) res[i] = rec.top()-i;
        rec.push(i);
    }
    return res;
}
};