class Solution {
public:
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    // cord = { singal, size }
    // cord = { singal, queryID }
    // unordered_map<int,set<pair<int,int>>> line;
    // line has to be sorted
    map<int,set<pair<int,int>>> line;
    // priority -> ending > starting > query
    for(auto i : intervals){
        line[i[0]].insert({1, i[1]-i[0]+1});
        line[i[1]].insert({10, i[1]-i[0]+1});
    }
    for(int q=0; q<queries.size(); q++) line[queries[q]].insert({2, q});

    vector<int> res(queries.size());
    // priority queue or
    // multiset<pair<int,int>> minheap;
    multiset<int> minSizes;
    for(auto it: line){
        // cout << "x cord : " <<it.first << endl;
        // trace all points on x axis
        for(auto &[signal, value] : it.second){
            // cout <<"signal : " << signal << " value : " << value << endl;
            if(signal == 10) {
                // delete one particular value
                auto delItr = minSizes.find(value);
                minSizes.erase(delItr);
                // minheap.erase({signal, value});
            }
            else if(signal == 1) {
                minSizes.insert(value);
                // minheap.insert({signal, value});
                }
            else{
                // if(minheap.size() == 0) res[value] = -1;
                // else{
                //     res[value] = minheap.begin()->first;
                // }
                // cout << "heap size " << minSizes.size() << endl;
                if(minSizes.size() == 0) res[value] = -1;
                else{
                    res[value] = *minSizes.begin();
                }
            }
        }
    }
    return res;
}
};