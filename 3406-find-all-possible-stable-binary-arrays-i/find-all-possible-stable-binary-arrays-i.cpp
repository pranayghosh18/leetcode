class Solution {
public:
    
// void static FastIO()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // return 0;
// }

    
int limit_100292;
int mod;
// map<string, int> dp_100292;
// int dp_[201][201][2][201];
vector<vector<vector<vector<int>>>> dpx;

int util_100292(int zero, int one, int last, int count){
    // base
    // if(zero == 0 && one == 0) return 1;
    // if(zero < 0 || one < 0) return 0;

    if(one > zero){
        if(limit_100292*(zero+1) < one) return 0;
    }
    if(zero > one){
        if(limit_100292*(one+1) < zero) return 0;
    }
    // if(zero == 0){
    //     if(one > limit_100292) return 0;
    //     return 1;
    // }
    
    // if(one == 0){
    //     if(zero > limit_100292) return 0;
    //     return 1;
    // }
    if(one == 0 || zero == 0) return 1;
    // string key = to_string(zero) + "#" + to_string(one) + "%" + to_string(last) + "&" + to_string(count);
    // if(dp_100292.find(key) != dp_100292.end()) return dp_100292[key];

    // if(dp_[zero][one][last][count] != -1) return dp_[zero][one][last][count];
    if(dpx[zero][one][last][count] != -1) return dpx[zero][one][last][count];

    int x(0), y(0);
    if(last == 0){
        if(count< limit_100292){
            x = util_100292(zero-1, one, 0, count+1);
        }
        y = util_100292(zero, one-1, 1, 1);
    }
    else{
        if(count< limit_100292){
            x = util_100292(zero, one-1, 1, count+1);
        }
        y = util_100292(zero-1, one, 0, 1);
    }
    // return dp_100292[key] = (x+y)%mod;
    // return dp_[zero][one][last][count] = (x+y)%mod;
    return dpx[zero][one][last][count] = (x+y)%mod;
}

int numberOfStableArrays(int zero, int one, int limit) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    limit_100292 = limit;
    mod = 1e9+7;
    // memset(dp_, -1, sizeof(dp_[0][0][0][0]) * 201 * 201 * 2 * 201);

// vector<vector<vector<vector<int>>>>
 dpx.resize(zero+1, vector<vector<vector<int>>>(one+1, vector<vector<int>>(2, vector<int>(limit+1, -1))));

    return (util_100292(zero-1, one, 0, 1) + util_100292(zero, one-1, 1, 1))%mod;
}
};