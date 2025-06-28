class Solution {

private:
    int canBecomeZero(const vector<int>& nums, const vector<vector<int>>& queries, int k){
        vector<int> differences(nums.size() + 1, 0);
        for(int i = 0; i < k; i++) {
            int qBegin = queries[i][0];
            int qEnd = queries[i][1];
            int qDecrease = queries[i][2];

            differences[qBegin] += qDecrease;
            differences[qEnd + 1] -= qDecrease;
        }

        //calculate prefix sum of differences.
        //if any are less than num we cannot 0 out

        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += differences[i];
            if(sum < nums[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0;
        int r = queries.size();
        int smallest = INT_MAX;

        while(l <= r) {
            int m = (l + r) / 2;

            bool canUse = canBecomeZero(nums, queries, m);
            if(canUse) {
                smallest = min(smallest, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if(smallest == INT_MAX) {
            return -1;
        }
        return smallest;
    }
};