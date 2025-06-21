class Solution {
public:
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool first(false), second(false), third(false);

    for(auto t:triplets){
        // check if current triplet is valid
        if(t[0] <= target[0]
         &&t[1] <= target[1]
         &&t[2] <= target[2]){
            if(t[0] == target[0]) first = true;
            if(t[1] == target[1]) second = true;
            if(t[2] == target[2]) third = true;

            if(first & second & third) return true;
         }
    }
    return false;
}
};