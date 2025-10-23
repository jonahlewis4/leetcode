class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int endOfThisJumpRange = 0;
        int nextEnd = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > endOfThisJumpRange) {
                jumps++;
                endOfThisJumpRange = nextEnd;
            }

            int nextSquare = i + nums[i];
            if(nextSquare > nextEnd) {
                nextEnd = nextSquare;
            }
        }


        return jumps;
    }
};