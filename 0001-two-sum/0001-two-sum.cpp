class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int compliment = target - num;
            if(map.find(compliment) != map.end()){
                return {i, map[compliment]};
            }
            map[num] = i;
        }
        return {};
    }
};