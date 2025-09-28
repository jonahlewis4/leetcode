class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int best = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 2 < nums.size(); i++) {
            int s1 = nums[i];
            int s2 = nums[i + 1];
            int s3 = nums[i + 2];
            if(s1 + s2 <= s3) {
                continue;
            }
            best = max(best, s1 + s2 + s3);
        }
        return best;
    }
};