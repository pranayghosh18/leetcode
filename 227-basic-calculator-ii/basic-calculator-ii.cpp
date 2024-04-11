class Solution {
public:
#define ll long long
ll exeOperation(ll a, ll b, char op){
    switch (op)
    {
    case '/': return a/b;
    case '*': return a*b;
    case '+': return a+b;
    case '-': return a-b;
    default:
        return 0;
    }
    return 0;
}
int calculate(string s) {
    stack<ll> operands;
    stack<char> operators;
    unordered_map<char, int> operatorPrecedance = {{'/', 4},
                                                    {'*', 4},
                                                    {'+', 2},
                                                    {'-', 2}};
    ll curNumb(0);
    for(char c : s){
        if(c==' ') continue;
        else if(c >= '0' && c<= '9') curNumb = (curNumb * 10) + (ll)(c-'0');
        else{
            if(operators.empty() || operatorPrecedance[operators.top()] < operatorPrecedance[c]) {
                operands.push(curNumb);
                curNumb = 0;
                operators.push(c);
            }
            else{
                operands.push(curNumb);
                curNumb = 0;
                while (!operators.empty() && operatorPrecedance[operators.top()] >= operatorPrecedance[c])
                {
                    ll b = operands.top();
                    operands.pop();
                    ll a = operands.top();
                    operands.pop();
                    ll newElem = exeOperation(a, b, operators.top());
                    operators.pop();
                    // curNumb = 0;
                    operands.push(newElem);
                    // operators.push(c);
                }
                operators.push(c);
            }
        }
    }
    operands.push(curNumb);
    while (operands.size() > 1)
    {
        ll b = operands.top();
        operands.pop();
        ll a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        operands.push(exeOperation(a,b,op));
    }
    
    return operands.top();
}
};