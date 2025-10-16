class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> vals(value, 0);
        
        int maxVal = nums.front();
        for(const int i : nums) {
            int modded = ((i % value) + value) % value;
            vals[modded]++;
            maxVal = max(maxVal, i);
        }

        for(int i = 0; true; i++) {
            int modded = i % value;
            if(vals[modded] == 0) {
                return i;
            }
            vals[modded]--;
        }

        return maxVal;
    }
};