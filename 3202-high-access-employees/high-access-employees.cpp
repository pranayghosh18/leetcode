class Solution {
public:
vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    unordered_map<string, vector<int>> access;
    for(auto rec : access_times){
        string emp = rec[0];
        for(int i=1; i<rec.size(); i++) access[emp].push_back(stoi(rec[i]));
    }        
    vector<string> ans;
    for(auto& [rec, list] : access) {
        string emp = rec; // .first;
        sort(list.begin(), list.end());
        for(int r=0, f=0; r<list.size(); r++){
            if(r-f >= 2) {
                // checking the fixed window within a hour
                if(list[r] - list[f] < 100){
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