class Solution {
public:
vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    struct data
    {
        int position;
        int health;
        char direction;
        int index;
    };
    vector<data> elements;
    for(int i=0; i<positions.size(); i++){
        data elem;
        elem.position = positions[i];
        elem.health = healths[i];
        elem.direction = directions[i];
        elem.index = i;

        elements.push_back(elem);
    }

    sort(elements.begin(), elements.end(), [](data &a, data &b)
                                            { return a.position < b.position;
                                            });
    stack<data> records;
    for(int i=0; i<elements.size(); i++){
        data elem = elements[i];
        // if(records.empty()) records.push(elem);
        // else{
        bool isInserted(true);
        while (!records.empty() && records.top().direction == 'R' && elem.direction == 'L')
        {
            // 3 cases
            // top > elem
            if(records.top().health > elem.health){
                records.top().health--;
                isInserted = false;
                break;
            }
            // elem > top
            else if(elem.health > records.top().health) {
                records.pop();
                elem.health--;
                isInserted = true;
            }
            // both same
            else{
                records.pop();
                isInserted = false;
                break;
            }
        }

        if(isInserted) records.push(elem);
    }
    // index, health
    vector<pair<int,int>> indexedHealth;
    while (!records.empty())
    {
        data elem = records.top();
        records.pop();
        indexedHealth.push_back({elem.index, elem.health});
    }
    sort(indexedHealth.begin(), indexedHealth.end());
    vector<int> ans;
    for(auto p : indexedHealth) ans.push_back(p.second);
    return ans;
}
};