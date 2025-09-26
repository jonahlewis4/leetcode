class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++){
                int neededLength = nums[i] + nums[j] - 1;
                vector<int>::iterator it = (upper_bound(nums.begin() + j + 1, nums.end(), neededLength));
                int numLTE = it - (nums.begin() + j + 1);
                total += numLTE;
            }
        }
        return total;
    }
};