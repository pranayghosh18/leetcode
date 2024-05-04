class Solution {
public:
    
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int i(0), j(people.size()-1);
    int res(0);
    while(i<=j){
        // take fatty or fatty + skinny
        if(people[i] + people[j] <= limit){
            i++; 
            j--;
        }
        else{
            j--;
        }
        res++;
    }     
    return res;   
}
};