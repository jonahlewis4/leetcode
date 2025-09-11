class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        int end = 0;
        int jumps = 0;

        int nextEnd = nums.front();

        for(int i = 0; i < nums.size() - 1; i++) {

            int reachable = i + nums[i];
            nextEnd = max(reachable, nextEnd);

            if(i == end) {
                end = nextEnd;
                jumps++;
            }
        }
        return jumps; 
    }  
};