class Solution {
public:
    
bool schema_809(string s, string t){
    int i(0),j(0),next_i, next_j;
    while(i<s.size() && j <t.size()){
        if(s[i] != t[j]) return false;
        // compute nexts
        next_i = i+1;
        while(next_i < s.size() && s[next_i]==s[next_i-1]) next_i++;
        int s_window = next_i-i;

        next_j = j+1;
        while(next_j < t.size() && t[next_j]==t[next_j-1]) next_j++;
        int t_window = next_j-j;

        if(s_window < t_window) return false;
        // l -> ll
        if(s_window > t_window && s_window < 3) return false;

        i = next_i;
        j = next_j;
    }
    return i==s.size() && j==t.size();
}
int expressiveWords(string s, vector<string>& words) {
    int res(0);
    for(string t : words) res += schema_809(s,t);
    return res;
}
};