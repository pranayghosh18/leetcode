class Solution {
public:
    
string countOfAtoms(string formula) {
    stack<pair<string, int>> stk;    
    int i(0);
    while (i<formula.size())
    {
        if(formula[i] == '(') stk.push({string(1, formula[i++]), -1});
        else if(formula[i] == ')'){
            i++;
            int freq(0);
            while (i<formula.size() && isdigit(formula[i])) freq = freq*10 + formula[i++] - '0';
            if(freq == 0) freq=1;
            vector<pair<string, int>> temp;
            while (stk.top().first != "(")
            {
                temp.push_back(stk.top());
                stk.pop();
            }
            // ( one
            stk.pop();
            // refill with upgrade freq
            while (temp.size() > 0)
            {
                stk.push({temp.back().first, temp.back().second*freq});
                temp.pop_back();
            }
        }
        else{
            string symbol(1, formula[i++]);
            while (i<formula.size() && isalpha(formula[i]) && islower(formula[i])) symbol.push_back(formula[i++]);
            int freq(0);
            while (i<formula.size() && isdigit(formula[i])) freq = freq*10 + formula[i++] - '0';
            if(freq == 0) freq=1;
            stk.push({symbol, freq});
        }
    }

    map<string, int> atomToCount;
    while (!stk.empty())
    {
        atomToCount[stk.top().first] += stk.top().second;
        stk.pop();
    }
    string ans;
    for(auto it: atomToCount) {
        ans += it.first;
        if(it.second > 1) ans += to_string(it.second);
    }
    return ans;
}
};