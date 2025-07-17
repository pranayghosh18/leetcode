class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    unordered_map<string, vector<int>> access;
    for(auto rec : access_times){
        string emp = rec[0];
        for(int i=1; i<rec.size(); i++) access[emp].push_back(stoi(rec[i]));
    }        
    vector<string> ans;
    for(auto rec : access) {
        string emp = rec.first;
        sort(rec.second.begin(), rec.second.end());
        for(int r=0, f=0; r<rec.second.size(); r++){
            if(r-f >= 2) {
                // checking the fixed window within a hour
                if(rec.second[r] - rec.second[f] < 100){
                    ans.push_back(emp);
                    break;
                }
                f++;
            }
        }
    }
    return ans;
}
};