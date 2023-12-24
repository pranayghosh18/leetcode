class Solution {
public:
    
int minOperations(string s) {
    int oz(0), zo(0);
    bool even = true;
    for(char c : s){
        if(even){
            // if(c != '0') zo++;
            // if(c != '1') oz++;
            
            if(c == '1') zo++;
            else{
                oz++;
            }
        }
        else{
            // if(c != '1') zo++;
            // if(c != '0') oz++;
            if(c == '0') zo++;
            else{
                oz++;
            }
        }
        even = !even;
    }        
    return min(oz,zo);
}
};