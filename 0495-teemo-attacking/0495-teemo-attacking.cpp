class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        for(int i = 0; i < timeSeries.size(); i++) {
            int curr = timeSeries[i];

            if(i + 1 < timeSeries.size() && timeSeries[i + 1] <= curr + duration - 1){
                res += timeSeries[i + 1] - curr;
            } else {
                res += duration;
            }
        }

        return res;
    }
};