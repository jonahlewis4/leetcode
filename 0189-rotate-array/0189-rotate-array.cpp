class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int idx = 0;
        int prev = nums[0];
        int start = 0;
        for(int c = 0; c < nums.size();){
            while(true){
                int newIdx = (idx + k) % nums.size();
                int tempPrev = nums[newIdx];
                nums[newIdx] = prev;
                prev = tempPrev;
                idx = newIdx;


                c++;
                if(start == idx){
                    idx += 1;
                    idx %= nums.size();
                    start = idx;
                    prev = nums[idx];
                    break;
                }
            }
        }
    }
};