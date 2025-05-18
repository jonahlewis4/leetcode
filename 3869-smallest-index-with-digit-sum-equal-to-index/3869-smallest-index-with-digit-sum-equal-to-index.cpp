class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(digitSum(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
    int digitSum(int i) const {
        int sum = 0;
        while(i > 0){
            int digit = i % 10;
            i /= 10;
            sum += digit;
        }
        return sum;
    }
};