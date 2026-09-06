class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % n == 0) {
                continue;
            }
            int slow = i;
            int fast = i;
            int dir = nums[i];
            while(true) {
                if(nums[slow] * dir <= 0) {
                    break;
                }
                if(nums[fast] * dir <= 0){
                    break;
                }

                int nextFast = ((fast + nums[fast]) % n + n ) % n;
                if(nums[nextFast] * dir <= 0) {
                    break;
                }

                slow = ((slow + nums[slow]) % n + n) % n;
                fast = ((nextFast + nums[nextFast]) % n + n) % n;
                if(slow == fast) {
                    if(slow == ((slow + nums[slow]) % n + n) % n) {
                        break;
                    }
                    return true;
                }
            }

            int curr = i;
            while(nums[curr] * dir > 0) {
                int next = ((curr + nums[curr]) % n + n) % n;
                nums[curr] = 0;
                curr = next;
            }
        }
        return false;
    }
};