class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int lastEnd = 0;
        for(const vector<int>& i : intervals) {
            int start = i.front();
            int end = i.back();

            
            if(start < lastEnd){
                return false;
            }
            lastEnd = end;
        }

        return true;
    }
};