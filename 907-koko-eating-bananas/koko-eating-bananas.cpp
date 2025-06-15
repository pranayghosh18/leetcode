class Solution {
public:

bool possibleToEat(vector<int>& piles, int k, int h) {
    int req(0);
    for(int p : piles){
        req += p/k;
        if(p%k != 0) req++;
        if(req > h) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int minDays(1);
    int maxDays = *max_element(piles.begin(), piles.end());
    while(minDays < maxDays){
        int kthDay = minDays + (maxDays - minDays)/2;
        // if valid, ko keep the val
        if(possibleToEat(piles, kthDay, h)) maxDays = kthDay;
        else minDays = kthDay + 1;
    }
    return minDays;
}
};