class Solution {
public:
string nearestPalindromic(string n) {
    int len = n.size();
    if(len == 1){
        int val = stoi(n);
        return to_string(val-1);
    }

    vector<string> candidates;
    // 1up candidate
    string up(len+1, '0');
    up[0] = '1';
    up.back() = '1';
    candidates.push_back(up);
    // 1 down candidate
    string down(len-1, '9');
    candidates.push_back(down);
    // panlindromic resconstruct
    string palin;
    for(int i=0; i<len/2; i++) palin.push_back(n[i]);
    
    if(len&1){
        string palinMain = palin;
        string palinRev = palin;
        reverse(palinRev.begin(), palinRev.end());
        palin.push_back(n[len/2]);
        // colne palin
        palin += palinRev;
        candidates.push_back(palin);
        // mid 1 down
        if(n[len/2] > '0'){
            palin = palinMain;
            palin.push_back(n[len/2]-1);
            palin += palinRev;
            candidates.push_back(palin);
        }
        // mid 1 up
        if(n[len/2] < '9'){
            palin = palinMain;
            palin.push_back(n[len/2]+1);
            palin += palinRev;
            candidates.push_back(palin);
        }
    }
    else{
        string palinMain = palin;
        string palinRev = palin;
        reverse(palinRev.begin(), palinRev.end());
        palin += palinRev;
        candidates.push_back(palin);

        palin = palinMain;
        long palinLong = stol(palin);
        // up last digit
        // if(palin.back() < '9'){
        //     palin = palinMain;
        //     char lastDigit = palin.back();
        //     palin.pop_back();
        //     palin.push_back(lastDigit+1);
        //     palinRev = palin;
        //     reverse(palinRev.begin(), palinRev.end());
        //     palin += palinRev;
        //     candidates.push_back(palin);
        // }
        string upPalin = to_string(palinLong+1);
        palinRev = upPalin;
        reverse(palinRev.begin(), palinRev.end());
        upPalin += palinRev;
        candidates.push_back(upPalin);

        // drop last digit
        // if(palin.back() > '0'){
        //     palin = palinMain;
        //     char lastDigit = palin.back();
        //     palin.pop_back();
        //     palin.push_back(lastDigit-1);
        //     palinRev = palin;
        //     reverse(palinRev.begin(), palinRev.end());
        //     palin += palinRev;
        //     candidates.push_back(palin);
        // }
        string downPalin = to_string(palinLong-1);
        palinRev = downPalin;
        reverse(palinRev.begin(), palinRev.end());
        downPalin += palinRev;
        candidates.push_back(downPalin);
    }

    string ans;
    long maxDistance(1e18);
    for(string s : candidates){
        cout << s << "\n";
        if(s==n) continue;
        long dist = abs(std::stol(n, nullptr, 10) - std::stol(s, nullptr, 10));
        if(dist == maxDistance){
            long anslong = stol(ans);
            long candiLong = stol(s);
            if(candiLong < anslong) ans=s; 
        }
        if(dist < maxDistance) maxDistance=dist, ans=s;
    }
    return ans;
}
};