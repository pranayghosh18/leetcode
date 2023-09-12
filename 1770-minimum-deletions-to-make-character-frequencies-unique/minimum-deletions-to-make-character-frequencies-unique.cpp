class Solution {
public:
    int minDeletions(string s) {
    //unordered_map<int,int> hm;
    vector<int> hm(26,0);
    for(char c : s) hm[c-'a']++;
    // sort the frequencies
    sort(hm.begin(),hm.end(),greater<>());
    int maxTill(-1),del(0);
    for(int count : hm){
        //int count = it->second;
        if(maxTill == -1) maxTill = count;
        else if(maxTill == 0){
            del += count;
        }
        else{
            if(count >= maxTill){
                // count be dropped to (maxTill-1)
                del += count - maxTill +1;
                maxTill--;
               // del++;
            }
            else{
                maxTill = count;
            }
        }
    }        
    return del;
}
};