class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        
        vector<int> res;
        if(a.size()==0 || b.size()==0 ) return res;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int i(0),j(0);
        while( i<a.size() && j<b.size() )
            {
                if(a[i]==b[j])
                    {
                        if(res.size()==0) res.push_back(a[i]);
                        else
                            {
                                if(a[i] != res[ res.size() - 1 ]) res.push_back(a[i]);
                            }
                        i++;
                        j++;
                    }
                else if (a[i] > b[j]) j++;
                else i++;
            }
        return res;
    }
};