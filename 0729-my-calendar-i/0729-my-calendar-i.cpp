class MyCalendar {
    set<pair<int ,int>> set;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        pair<int, int> time = {startTime, endTime};

        auto nextItr = set.upper_bound(time);

        //first check that it fits in with the one after.            
        bool afterOk = nextItr == set.end() || time.second <= nextItr->first;

        //next check that if fits in with the one before
        bool beforeOk = nextItr == set.begin() || time.first >= prev(nextItr)->second;
        
        bool noOverlap = afterOk && beforeOk;
        if(noOverlap) {
            set.insert(time);
        }
        return noOverlap;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */