class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>* stamps = &(map[key]);
        int l = 0;
        int r = stamps->size() - 1;
        pair<int, string>* best = nullptr;
        while(l <= r){
            int m = (l + r) / 2;
            pair<int, string>* mPtr = &stamps->at(m);
            int mVal = mPtr->first;
            if(mVal == timestamp){
                return mPtr->second;
            }
            if(mVal < timestamp){
                if(best == nullptr || mVal > best->first){
                    best = mPtr;
                }
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if(best == nullptr){
            return "";
        }
        return best->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */