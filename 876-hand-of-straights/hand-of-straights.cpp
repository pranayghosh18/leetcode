class Solution {
public:

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size() % groupSize != 0) return false;
    map<int,int> hm;
    for(int h:hand) hm[h]++;

    // not deleting from the hashmap
    for(auto it: hm){
        int elem = it.first;
        int count = it.second;
        cout << "elem " << elem << "  count " << count << endl;
        if(count == 0) continue;

        for(int i=1; i<groupSize; i++) {
            if(hm[elem + i] < count) return false;
            hm[elem + i] -= count;
        }
    }
    return true;
}
};