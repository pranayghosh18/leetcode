class Solution {
public:

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(int i=0; i<tokens.size(); i++){
        if(tokens[i] == "+") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a+b);
        }
        else if(tokens[i] == "-") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a-b);
        }
        else if(tokens[i] == "*") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a*b);
        }
        else if(tokens[i] == "/") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a/b);
        }
        else stk.push(stoi(tokens[i]));
    }
    return stk.top();
}
};