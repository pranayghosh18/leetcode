class Solution {
public:
double minAreaFreeRect(vector<vector<int>>& points) {
    map<pair<double,double>, vector<pair<int,int>>> originToPoints;

    for(int i=0; i<points.size(); i++){
        for(int j=i+1; j<points.size(); j++){
            double x = ((double) (points[i][0] + points[j][0])) / 2;
            double y = ((double) (points[i][1] + points[j][1])) / 2;
            
            originToPoints[{x,y}].push_back({i, j});
        }
    }
    double res(1e9);
    for(auto origin : originToPoints){
        // cout << "origin : " << origin.first.first << "," << origin.first.second << endl;
        // cout << "points pair : " << origin.second.size() << endl;
        for(int i=0; i<origin.second.size(); i++){
            for(int j=i+1; j<origin.second.size(); j++){
                int a = origin.second[i].first;
                int b = origin.second[i].second;
                int c = origin.second[j].first;
                int d = origin.second[j].second;
                
                // cout << "a " << a << " b " << b << " c "<< c <<  " d " << d << endl;
                // cout << pow((points[a][0] - points[c][0]), 2) << " | " << pow((points[a][1] - points[c][1]), 2) << endl;

                double acSq = pow((points[a][0] - points[c][0]), 2) + pow((points[a][1] - points[c][1]), 2);
                double adSq = pow((points[a][0] - points[d][0]), 2) + pow((points[a][1] - points[d][1]), 2);
                // cout << "ac : " << acSq << " bd : " << adSq << endl;
                // check if diagonal length also same
                double abSq = pow((points[a][0] - points[b][0]), 2) + pow((points[a][1] - points[b][1]), 2);
                double cdSq = pow((points[d][0] - points[c][0]), 2) + pow((points[d][1] - points[c][1]), 2);
                
                if(abSq == cdSq) res = min(res, sqrt(acSq*adSq));
            }
        }
    }

    return res == 1e9? 0 : res;
}
};