class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int front = nums[0];
        int size = 1;
        for(const auto & num : nums) {
            if(num - front > k){
                front = num;
                size++;
            }
        }


        return size;
    }
};