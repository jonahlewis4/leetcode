class TwoSum {
public:
    unordered_set<int> twosum_set;
    unordered_set<int> s;
    TwoSum() {
        
    }
    
    void add(int number) {
        if(s.find(number)==s.end()) {
            for(auto &i:s) twosum_set.insert(number+i);
            s.insert(number);
        } else {
            twosum_set.insert(2*number);
        }
    }
    
    bool find(int value) {
        return twosum_set.find(value)!=twosum_set.end();
    }
};