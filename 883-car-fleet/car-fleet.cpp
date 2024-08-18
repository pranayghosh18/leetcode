class Solution {
public:
#define ll long long
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> posSpeed;
    for(int i=0; i<position.size(); i++) posSpeed.push_back({position[i], speed[i]});
    sort(posSpeed.begin(), posSpeed.end());

    int count(0), prevSpeed(1), prevDist(0);
    for(int i=posSpeed.size()-1; i>=0; i--){
        int distance = target - posSpeed[i].first;
        int velocity = posSpeed[i].second;
        // this cars time > prev some cars time
        // ie this car come as a isolated one
        if((ll)distance*(ll)prevSpeed > (ll)prevDist*(ll)velocity){
            count++;
            prevDist = distance;
            prevSpeed = velocity;
        }
        // else, current car getting merged with the fleet
    }     
    return count;   
}
};