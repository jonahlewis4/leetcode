class Solution {
private:




public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for(const auto & interval : intervals){
            events.push_back({interval[0], 1});
            events.push_back({interval[1], -1});
        }

        sort(events.begin(), events.end());
        
        int rooms = 0;
        int maxRooms = 0;
        for(const auto & event : events){
            rooms += event.second;
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }    
};