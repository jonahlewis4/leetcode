class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (!first.count(x)) {
                first[x] = i;
            }
            last[x] = i;
            count[x]++;
        }

        int degree = 0;
        for (auto& [num, c] : count) {
            degree = max(degree, c);
        }

        int ans = nums.size();
        for (auto& [num, c] : count) {
            if (c == degree) {
                ans = min(ans, last[num] - first[num] + 1);
            }
        }

        return ans;
    }
};
