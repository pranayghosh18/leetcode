class Solution {
public:
 
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    int maxFreq(0);
    for(char t : tasks) freq[t]++, maxFreq=max(maxFreq, freq[t]);
    int ans((maxFreq-1)*(n+1));    
    for(auto t : freq) if(t.second == maxFreq) ans++;
    return max(ans, int(tasks.size()));
}
};