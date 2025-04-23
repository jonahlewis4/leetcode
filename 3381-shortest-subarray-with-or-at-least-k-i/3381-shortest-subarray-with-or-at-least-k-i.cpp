class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLen = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int _or = 0;
            for(int j = i; j < nums.size(); j++){
                _or |= nums[j];
                if(_or >= k){
                    minLen = min(minLen, j - i + 1);
                }
            }
        }


        return minLen == INT_MAX ? -1 : minLen;
    }
};