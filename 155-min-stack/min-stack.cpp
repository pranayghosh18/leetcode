class MinStack {
public:
    stack<pair<int,int>> s;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push({x, s.empty() || s.top().second > x ? x : s.top().second});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */