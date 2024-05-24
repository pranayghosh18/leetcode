class Solution {
public:
int util_1255(vector<string>& words, vector<int>& charFreq, vector<int>& score, int mask){
    // stroe the freq
    vector<int> freq(26, 0);
    int idx(0);
    while(mask > 0){
        if(mask & 1){
            for(char c : words[idx]) freq[c-'a']++;
        }
        mask >>= 1;
        idx++;
    }

    int res(0);
    for(int i=0; i<26; i++){
        if(freq[i] > charFreq[i]) return 0;
        res += (score[i]*freq[i]);
    }
    
    return res;
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<int> charFreq(26, 0);
    for(char l : letters) charFreq[l-'a']++;

    int res(0);
    int n = words.size();
    // try all possibilities
    for(int i=1; i<(1<<n); i++) res = max(res, util_1255(words, charFreq, score, i));

    return res;
}
};