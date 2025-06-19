class Solution {
public:
    string removeKdigits(string s, int k) {
        // if(s.size() >= 10000) return "";
        stack<char> st;
        int i(0);
        while(i<s.size()){
            if(st.empty()){
                st.push(s[i]);
                i++;
            }
            else{
                while( !st.empty() && k>0 && st.top() > s[i]){
                    st.pop();
                    k--;
                }
                st.push(s[i]);
                i++;
            }
        }
        string r;
        // filling res str
        while(!st.empty()){
            r.push_back(st.top());
            st.pop();
        }
        // cout << "27 line : " << r << endl;
        // cout << "r back : " << r.back() << endl;
        // delete right 0s
        while(r.size() > 0 && r.back()=='0') r.pop_back();
        // cout << "30 line : " << r << endl;

        // if(r.size() > 0) 
        reverse(r.begin(),r.end());
        // str is not like 123456
        while(k>0 && r.size() > 0){
            r.pop_back();
            k--;
        }
        if(r.size()==0) return "0";
        return r;
    }
};