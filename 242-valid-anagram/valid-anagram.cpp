class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> box(26);
        for(char c : s) { box[c - 'a'] = box[c - 'a'] + 1; }
        for(char c : t) { box[c - 'a'] = box[c - 'a'] - 1; }
        /*
        for(int i = 0; i<s.size(); i++)
            {
                int dx = s[i] - 'a';
                box[dx]++;
            }
        for(int i = 0; i<t.size(); i++)
            {
                int dx = t[i] - 'a';
                box[dx]--;
            }
        */
        for(int i : box)  { if( i != 0) return false; }
        return true;
    }
};