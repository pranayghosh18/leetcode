class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        int a[26] = {0};
        for(char c : tasks) a[c-'A']++;
        priority_queue<int> mxh;
        for(int i : a) if(i > 0) mxh.push(i);
        int tq = n+1;
        int period(0);
       while(!mxh.empty()){
            // pick n tasks and reduce there time quantum by 1
            multiset<int> next_cycle;
            int executed(0);
            for(int i=1; i<=tq && !mxh.empty(); i++) {
                if(mxh.top()-1 > 0) next_cycle.insert( mxh.top()-1 );
                mxh.pop();
                executed++;
                }
            if(next_cycle.empty() && mxh.empty()){
                period += executed;
                return period;
            }
            period += max(executed, tq);
            for(int i : next_cycle) mxh.push(i);
        }
        return period;
    }
};