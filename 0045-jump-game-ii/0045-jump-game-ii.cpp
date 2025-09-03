class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int nextStart = 0;
        int nextEnd = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            nextStart = max(nextStart, i + nums[i]);


            if(i == nextEnd) {
                nextEnd = nextStart;
                jumps++;
            }
        }
        return jumps;
    }
};