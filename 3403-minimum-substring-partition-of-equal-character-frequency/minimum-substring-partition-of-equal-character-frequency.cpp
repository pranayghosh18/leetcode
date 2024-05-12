class Solution {
public:
bool validStr(string s){
    unordered_map<char, int> hm;
    for(char c : s) hm[c]++;
    int p(-1);
    for(auto it : hm){
        if(p==-1) p = it.second;
        else{
            if(p != it.second) return false;
        }
    }
    return true;
}
bool validStrHm(unordered_map<char, int>& hm1, unordered_map<char, int>& hm2){
// cout <<"hm1 s " << hm1.size() << "hm2 s " << hm2.size() << endl;
    unordered_map<char, int> hm3;
    for(auto it : hm2){
        hm3[it.first] = it.second - hm1[it.first];
    }

    int p(-1);
    for(auto it : hm3){
        if(it.second == 0) continue;
        // int diff = it.second - hm1[it.first];
        if(p==-1) p = it.second;
        else{
            if(p != it.second) return false;
        }
    }
    return true;
}
void printVector(vector<int> v){
    for(auto t : v) cout << t <<"\t";
    cout << endl;
}

bool validFrequency(vector<vector<int>>& rec, int b, int e){
    // cout << "e : " << e << endl;
    // printVector(rec[e]);
    // cout << "b : " << b << endl;
    // printVector(rec[b]);
    // cout <<"-----------------------\n";
    int prev(-1);
    for(int i=0; i<26; i++){
        int dif = rec[e][i] - (b==-1? 0 : rec[b][i]);
        if(dif !=0 && prev == -1) prev = dif;
        if(dif !=0 && prev != dif) return false;
    }
    return true;
}

int minimumSubstringsInPartition(string s) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<int> dp(s.size(), 1e5);
    // vector<unordered_map<char, int>> charList(s.size());
    vector<vector<int>> rec(s.size());

    unordered_map<char, int> cur;
    vector<int> freq(26,0);
    for(int i=0; i<s.size(); i++){
        // cur[s[i]]++;
        // charList[i] = cur;

        freq[s[i] - 'a']++;
        rec[i] = freq;
    }


    dp[0] = 1;
    for(int i=1; i<s.size(); i++){
        for(int j=i; j>=0; j--){
            int prev = j==0? 0 : dp[j-1];
            // string slice = s.substr(j, i-j+1);
            // if(dp[i] > prev+1 && validStr(slice)){
            //     dp[i] = min(dp[i], 1+prev);
            // }
            // if(j==0){
            //     if(validStr(s.substr(0, i+1))) dp[i] = 1;
            // }
            // else{
            //     if(dp[i] > prev+1 && validStrHm(charList[i], charList[j-1])) dp[i] = min(dp[i], 1+prev);
            // }
            if(dp[i] > prev+1 && validFrequency(rec, j-1, i)) dp[i] = min(dp[i], 1+prev);
        }
    }
    return dp.back();
}
};