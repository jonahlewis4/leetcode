class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int mismatch = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(sorted[i] != heights[i]){
                mismatch++;
            }
        }
        return mismatch;
    }
};