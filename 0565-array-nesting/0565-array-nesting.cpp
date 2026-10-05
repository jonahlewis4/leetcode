class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int best = 0;
        for(int i = 0; i < nums.size(); i++) {
            int cycLen = 0;
            int next = nums[i];
            while(next >= 0){
                int newNext = nums[next];
                nums[next] = -1;
                next = newNext;
                cycLen++;
            }

            best = max(cycLen-1, best);
        }

        return best;

    }
};