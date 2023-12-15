
class TimeMap {
public:
    unordered_map<string, map<int, string>> database;
    TimeMap() {      
    }
    
    void set(string key, string value, int timestamp) {
        database[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //if(database.find(key) == database.end()) return "";
        // auto keyMap = database[key];

        // auto lb = keyMap.lower_bound(timestamp);
        // if(lb!=keyMap.end() && lb->first == timestamp) return lb->second;
        // if(lb == keyMap.begin()) return "";
        // lb--;
        // return lb->second;

        auto ub = database[key].upper_bound(timestamp);
        if(ub == database[key].begin()) return "";
        ub--;
        return ub->second;
    }
    /*
        unordered_map<string, map<int, string>> m;
        void set(string key, string value, int timestamp) {
        m[key].insert({ timestamp, value });
        }
        string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
        }
    */
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */