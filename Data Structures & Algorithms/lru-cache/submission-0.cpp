class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> accessList;
    int capacity = 0;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!this->cache.count(key)) {
            return -1;
        }

        int value = this->cache[key].first;
        refresh(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (!this->cache.count(key) && this->capacity == this->accessList.size()) {
            this->cache.erase(this->accessList.front());
            this->accessList.pop_front();
        }
        refresh(key, value);
    }

    void refresh (int key, int value) {
        if (this->cache.count(key)) {
            this->accessList.erase(this->cache[key].second);
        } 
        this->accessList.push_back(key);
        auto it = this->accessList.end();
        it--;
        this->cache[key] = {value, it};
    }
};
