class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        if(itr == nums.end()) {
            return -1;
        }

        if(*itr != target) {
            return -1;
        }
        
        return itr - nums.begin();

    }
};