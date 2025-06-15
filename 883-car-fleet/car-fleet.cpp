class Solution {
public:
    
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,int>> elem;
    for(int i=0; i<position.size(); i++) elem.push_back({position[i], speed[i]});
    sort(elem.begin(), elem.end());
    long chunks(0), dp(0), vp(1);
    for(int i=elem.size()-1; i>=0; i--){
        long dc = target - elem[i].first;
        long vc = elem[i].second;
        if(dc * vp > dp * vc) {
            chunks++;
            dp = dc;
            vp = vc;
        }
    }        
    return chunks;
}
};