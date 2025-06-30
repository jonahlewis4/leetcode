class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        for(const auto & num : nums) {
            sum += num;
        }

        int leftSum = 0;
        int i = 0;
        for(const auto & num : nums ) {
            if(2 * leftSum + num == sum){
                return i;
            }
            i++;
            leftSum += num;
        }
        return -1;
    }
};