class Solution {
public:
    bool isPathCrossing(string path) {
    int h(0), w(0);
    set<pair<int,int>> seen;
    seen.insert({h,w});
    for(char p : path){
        switch (p)
        {
        case 'N': h++;
                  break;
        case 'S': h--;
                  break;
        case 'E': w++;
                  break;
        default : w--;
                break;
        }
        if(seen.find({h,w})!=seen.end()) return true;
        seen.insert({h,w});
    }        
    return false;
}
};