class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        unordered_set<int> inSet;
        while(r < nums.size()) {
            int lNum = nums[l];
            int rNum = nums[r];
            while(l < r && inSet.find(rNum) != inSet.end()) {
                inSet.erase(lNum);
                sum -= lNum;
                l++;
                lNum = nums[l];
            }
            inSet.insert(rNum);
            sum += rNum;
            maxSum = max(maxSum, sum); 
            r++;
        }
        return maxSum;
    }
};