class AllOne {
private:
    struct ListNode{
        int count = 0;
        unordered_set<string> set;
    };
    std::list<ListNode> list;
    unordered_map<string, std::list<ListNode>::iterator> map;
public:
    AllOne() {
        
    }
    void insert(const string& key){
        if(list.empty() || list.front().count != 1){
            map[key] = list.insert(list.begin(), {
                .count = 1,
                .set = {key},
            });
        } else {
            map[key] = list.begin();
            list.front().set.insert(key);
        }
    }
    void increase(const string& key){
        auto itr = map[key];
        auto next = std::next(itr);
        map.erase(key);
        if(next == list.end()){
            map[key] = list.insert(list.end(), {
                .count = itr->count + 1,
                .set = {key},
            });
        } else if (next->count != itr->count + 1){
            map[key] = list.insert(next, {
                .count = itr->count + 1,
                .set = {key}
            });
        } else {
            map[key] = next;
            next->set.insert(key);
        }


        itr->set.erase(key);
        if(itr->set.empty()){
            list.erase(itr);
        }
    }
    void inc(const string &key) {
        if(map.find(key) == map.end()){
            insert(key);
        } else {
            increase(key);
        }

    }
    void decrease(const string& key){
        auto itr = map[key];
        auto prev = std::prev(itr);
        map.erase(key);
        if(itr == list.begin()){
            map[key] = list.insert(list.begin(), {
                .count = 1,
                .set = {key},
            });
        } else if (prev->count != itr->count - 1){
            map[key] = list.insert(itr, {
                .count = itr->count - 1,
                .set = {key},
            });
        } else {
            map[key] = prev;
            prev->set.insert(key);
        }

        itr->set.erase(key);
        if(itr->set.empty()){
            list.erase(itr);
        }
    }
    void erase(const string& key){
        auto itr = map[key];
        itr->set.erase(key);
        if(itr->set.empty()){
            list.erase(itr);
        }
        map.erase(key);
    }
    void dec(const string &key) {
        if(map.find(key) == map.end()){
            throw "cannot decrement non existant key";
        } else if (map[key]->count == 1){
            erase(key);
        } else {
            decrease(key);
        }
        
    }
    
    string getMaxKey() {
        if(list.size() == 0){
            return "";
        }
        auto back = &list.back();
        return *back->set.begin();
    }
    
    string getMinKey() {
        if(list.size() == 0){
            return "";
        }
        return *list.front().set.begin();

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */