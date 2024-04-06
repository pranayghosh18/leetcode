class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<pair<char,int>> stk;
        int i(0);
        while(i<s.size()){
            
            if(s[i]=='(') stk.push({'(',i});
            
            if(s[i]==')'){
                
                if(!stk.empty() && stk.top().first=='(') stk.pop();
                else
                    stk.push({')',i});
            }
            i++;
        }
        
        i=s.size()-1;
        
        string ans;
        
        while(i>=0){
            
            if(!stk.empty() && stk.top().second==i) stk.pop();
            else
                ans.push_back(s[i]);
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};