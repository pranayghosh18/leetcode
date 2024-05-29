class Solution {
public:
    
int numSteps(string s) {
    int ans(0), carry(0);
    for(int i=s.size()-1; i>=1; i--){
        int sum = s[i]-'0' + carry;
        s[i] = sum%2 + '0';
        carry = sum/2;

        if(s[i] == '1') ans+=2, carry=1;
        else ans+=1;
    }        

    ans+= carry==1? 1 : 0;

    return ans;
}
};