class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (!store.count(key)) {
            return "";
        }

        auto& listTime = store[key];
        sort(listTime.begin(), listTime.end());
        auto  it = upper_bound(listTime.begin(), listTime.end(), timestamp,
                    [] (const int value, pair<int, string>& p) { return value < p.first ;}
        ) ;
        if (it == listTime.begin())
            return "";

        --it;
        return it->second;
    }
};
