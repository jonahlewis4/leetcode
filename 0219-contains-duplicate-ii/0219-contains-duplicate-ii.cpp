#include <unordered_map>
#include <cmath>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> lastSeenIOf;
        for(int i = 0; i < nums.size(); i++){
            const auto &num = nums[i];
            if(lastSeenIOf.find(num) != lastSeenIOf.end()){
                if(std::abs(lastSeenIOf[num] - i) <= k){
                    return true;
                }
            }
            lastSeenIOf[num] = i;
        }
        return false;
    }
};