#include <cmath>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> _set;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(_set.count(num)){
                return true;
            }
            _set.insert(num);
            if(i - k >= 0){
                _set.erase(nums[i - k]);
            }
        }
        return false;
    }
};