class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow == fast){
                break;
            }
        }

        int slow2 = 0;
        while(slow2 != slow){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};