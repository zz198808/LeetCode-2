class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        
        type_data::iterator it = data.find(key);
        
        if (it == data.end()) {
            return -1;
        }
        
        lru.erase(it->second.second);
        lru.push_front(key);
        it->second.second = lru.begin();
        
        return it->second.first;
    }
    
    void set(int key, int value) {
        type_data::iterator it = data.find(key);
        if (it != data.end()) {
            lru.erase(it->second.second);
        }
        lru.push_front(key);
        
        data[key] = make_pair(value, lru.begin());
        if (capacity < data.size()) {
            data.erase(lru.back());
            //lru.pop_back();
            lru.erase(--lru.rbegin().base());
        }
    }
private:
    list<int> lru;
    
    typedef unordered_map<int, pair<int, list<int>::iterator> > type_data;
    
    type_data data;
    int capacity;
};