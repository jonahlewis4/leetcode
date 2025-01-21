class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = INT_MIN;
        int l = 0;
        for(int r = 1; r < values.size(); r++){
            maxScore = max(maxScore, values[l] + values[r] + l - r);
            if(values[r] > (values[l] - (r - l))){
                l = r;
            }
        }
        return maxScore;
    }
};