class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            //if newInterval is 100% before the current one, add the new one, then add all the remaining
            if (intervals[i][0] > newEnd) {
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            //if newInterval is after the current one, add the new one
            } else if (intervals[i][1] < newStart) {
                res.push_back(intervals[i]);
            //default: it is meshed with the current one, so merge them and add them later.
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        //base case: we got to the end without ever adding in the new interval, so add it.
        //these would be the merged new interval.
        res.push_back(newInterval);
        return res;
    }
};