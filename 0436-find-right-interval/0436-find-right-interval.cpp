class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res(intervals.size());
        unordered_map<string, int> idx;
        for(int j = 0; j < intervals.size(); j++) {
            const vector<int>& i = intervals[j];
            idx[to_string(i.front()) + "," + to_string(i.back())] = j;
        }
        sort(intervals.begin(), intervals.end());

        for(const vector<int>& interval : intervals) {
            int i = idx[to_string(interval.front())+","+to_string(interval.back())];
            const auto& itr = lower_bound(intervals.begin(), intervals.end(), vector<int>{interval.back(), INT_MIN});
            if(itr == intervals.end()) {
                res[i] = -1;
                continue;
            }
            int i2 = idx[to_string(itr->front())+","+to_string(itr->back())];

            res[i] = i2;

        }
        return res;
    }
};