class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = nums.front();
        int num2Beat = INT_MAX;

        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if(num < smallest) {
                smallest = num;
            }

            if(num < num2Beat && num > smallest){
                num2Beat = num;
            }

            if(num > num2Beat) {
                return true;
            }
        }

        return false;
        
    }
};