class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = 0;
        int r = 2;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++){
                int neededLength = nums[i] + nums[j] - 1;
                while(r < nums.size() && nums[r] <= neededLength){
                    r++;
                }
                int numLTE = r - j - 1;
                total += numLTE;
            }
        }
        return total;
    }
};