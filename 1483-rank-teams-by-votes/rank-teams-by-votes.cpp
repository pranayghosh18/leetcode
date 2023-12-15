class Solution {
public:
bool sorting_1366(char& a, char& b, unordered_map<char, vector<int>>& stats){
    for(int i=0; i<stats[a].size(); i++){
        if(stats[a][i] != stats[b][i]) return stats[a][i] > stats[b][i];
    }
    return a<b;
}
void basicBubbleSort_1366(string& s, unordered_map<char, vector<int>>& stats){
    for(int i=0; i<s.size(); i++){
        bool turn = false;
        for(int j=0; j<s.size()-1; j++){
            char a = s[j];
            char b = s[j+1];
            if(!sorting_1366(a,b,stats)) {
                swap(s[j], s[j+1]);
                turn = true;
                }
        }
        if(!turn) break;
    }
}
string rankTeams(vector<string>& votes) {
    int candidates = votes[0].size();
    unordered_map<char, vector<int>> stats;
    string allCandidates;
    for(string vote : votes){
        for(int position=0; position<vote.size(); position++){
            char candidate = vote[position];

            if(stats.find(candidate) == stats.end()){
                allCandidates.push_back(candidate);
                vector<int> statLine(candidates,0);
                stats[candidate] = statLine;
            }
            stats[candidate][position]++;
        }
    }
// // printing
// for(auto key : stats){
//     cout << key.first << endl;
//     for(int i : key.second) cout << i << "\t";
//     cout << endl;
// }
    basicBubbleSort_1366(allCandidates, stats);
    // sort(allCandidates.begin(), allCandidates.end(), sorting_1366);
    return allCandidates;
}
};