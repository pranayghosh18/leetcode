class Solution {
public:
    /*
    bool is(unordered_map<int,int> mp)
        {
            for(auto it : mp)
                {
                    if(it.second<0) return false;
                }
            return true;
        }
    */
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        
        for(char c : t) mp[c]--;
        
        int negs=mp.size();
        
        int i(0),j(0);
        if(mp.find(s[0]) != mp.end() )
            {
                mp[s[0]]++;
                if(mp[s[0]]==0) negs--;
            }
        
        int ans(INT_MAX);
        pair<int,int> p;
        
        while(j<s.size())
            {
                if(negs == 0)
                    {
                        if(ans > j-i+1)
                            {
                                ans = j-i+1;
                                p.first = i;
                                p.second = j;
                            }
                        if(mp.find(s[i]) != mp.end() )
                            {
                                if(mp[s[i]]==0) negs++;
                                mp[s[i]]--;
                            }
                        i++;
                    }
                else
                    {
                        j++;
                        if(j<s.size() && mp.find(s[j]) != mp.end() )
                            {
                                mp[s[j]]++; 
                                if(mp[s[j]]==0) negs--;
                                   
                            }
                    }
            }
        string res;
        if(ans==INT_MAX) return res;
        res = s.substr(p.first, p.second - p.first + 1);
        return res;
    }
};