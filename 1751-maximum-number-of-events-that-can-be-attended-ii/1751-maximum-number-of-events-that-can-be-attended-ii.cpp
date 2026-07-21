class Solution {

    vector<vector<int>> dp;

    int r(vector<vector<int>>& events, int eventIdx, int remainingPicks) {
        if(remainingPicks == 0) {
            return 0;
        }
        if(eventIdx >= events.size()) {
            return 0;
        }

        if(dp[eventIdx][remainingPicks - 1] != -1) {
            return dp[eventIdx][remainingPicks - 1];
        }
        
        vector<int>& event = events[eventIdx];
        int startDay = event[0];
        int endDay = event[1];
        int value = event[2];

        //time < startDay, so it *may* be used
        int dontAttend = r(events, eventIdx + 1, remainingPicks);
        vector<vector<int>>::iterator itr = upper_bound(
            events.begin() + eventIdx + 1, 
            events.end(), 
            endDay,
            [](int targetEndDay, const vector<int>& event) {
                return targetEndDay < event[0];
            }
        );
        int j = itr - events.begin();
        int attend = r(events, j, remainingPicks - 1);
        attend += value;
    
        int res = max(attend, dontAttend);
        dp[eventIdx][remainingPicks-1] = res;
        return res;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        dp.resize(events.size(), vector<int>(k, -1));
        sort(events.begin(), events.end());
        return r(events, 0, k);
    }
};