class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int distinct = nums.size();
        int lastUsed = INT_MIN;

        for(const int num : nums) {
            int minimized = num - k;
            if(minimized > lastUsed) {
                lastUsed = minimized;
                continue;
            }

            lastUsed++;
            if(lastUsed > num + k) {
                lastUsed = num + k;
                distinct--;
            }
        }
        return distinct;
    }
};