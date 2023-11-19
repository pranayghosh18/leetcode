class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
    int maxFreq(0), maxElem;
    long front(0), rear(0), curSum(0);
    // sliding window
    while(rear < arr.size()){
        int freq = rear-front+1;
        // if(freq > maxFreq){
        //     maxFreq = freq;
        //     maxElem = arr[rear];
        // }
        // extend
        if(curSum <= k){
            if(freq > maxFreq){
                maxFreq = freq;
                maxElem = arr[rear];
            }
            rear++;
            if(rear < arr.size()){
                long extension = (arr[rear]-arr[rear-1]) * (rear-front);
                curSum += extension;
            }
        }
        else{
            curSum -= (arr[rear]-arr[front]);
            front++;
        }
    }
    return maxFreq;   
    }
};