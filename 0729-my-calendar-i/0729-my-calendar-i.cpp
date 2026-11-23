class MyCalendar {
    set<pair<int ,int>> set;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        pair<int, int> time = {startTime, endTime};

        auto nextItr = set.upper_bound(time);           

        if(nextItr == set.begin()) {
            if(set.empty()) {
                set.insert(time);
                return true;
            }
            if(time.second > nextItr->first) {
                return false;
            }
            set.insert(time);
            return true;
        }

        auto prevItr = prev(nextItr);
        if(prevItr->second > time.first) {
            return false;
        }

        if(nextItr == set.end()) {
            set.insert(time);
            return true;
        }
        if(time.second > nextItr->first) {
            return false;
        }

        set.insert(time);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */