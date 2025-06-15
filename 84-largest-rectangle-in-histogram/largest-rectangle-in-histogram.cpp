class Solution {
public:

void printVec(vector<int>& v){
    for(int i : v) cout << i << "\t";
    cout << endl;
}

vector<int> nextSmallerIndex(vector<int>& ar){
    vector<int> res;
    stack<int> stk;
    for(int i=ar.size()-1; i>=0; i--){
        while(!stk.empty() && ar[i] <= ar[stk.top()]) stk.pop();
        res.push_back(stk.empty() ? ar.size() : stk.top());
        stk.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> prevSmallerIndex(vector<int>& ar){
    vector<int> res;
    stack<int> stk;
    for(int i=0; i<ar.size(); i++){
        while(!stk.empty() && ar[i] <= ar[stk.top()]) stk.pop();
        res.push_back(stk.empty() ? -1 : stk.top());
        stk.push(i);
    }
    return res;
}

int largestRectangleArea(vector<int>& heights) {
    // for each bar how much can expand
    // each bar needs to know smallest on left and smallest on right
    vector<int> nextSmaller = nextSmallerIndex(heights);
    vector<int> prevSmaller = prevSmallerIndex(heights);
    // printVec(nextSmaller);
    // printVec(prevSmaller);
    int ans(0);
    for(int i=0; i<heights.size(); i++) ans = max(ans, (nextSmaller[i]-prevSmaller[i]-1)*heights[i]);
    return ans;
}
};