class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    vector<int> glass(garbage.size(),0),metal(garbage.size(),0),paper(garbage.size(),0);
    int last_p(-1), last_g(-1), last_m(-1);
    for(int i=0; i<garbage.size(); i++){
        int p(0),m(0),g(0);
        for(char c : garbage[i]){
            if(c=='M') last_m=i, m++;
            if(c=='P') last_p=i, p++;
            if(c=='G') last_g=i, g++;
        }
        glass[i] = g;
        metal[i] = m;
        paper[i] = p;
    }

    int res(0);
    for(int i=0; i<=last_p; i++){
        res += paper[i];
        if(i!=last_p) res += travel[i];
    }
    for(int i=0; i<=last_g; i++){
        res += glass[i];
        if(i!=last_g) res += travel[i];
    }
    for(int i=0; i<=last_m; i++){
        res += metal[i];
        if(i!=last_m) res += travel[i];
    }

    return res;
}
};