class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int old1 = 0;
        int old2 = 0;
        int old3 = 0;
        int new1 = 0;
        int new2 = 0;
        int new3 = 0;
        int prevVal = nums.front() - 2;
        for(const int num : nums){
            int diff = num - prevVal;
            if(diff > 0){
                if(old1 || old2) {
                    return false;
                }
                old1 = new1;
                old2 = new2;
                old3 = new3;
                new1 = 0;
                new2 = 0;
                new3 = 0;
                if(diff > 1){
                    if(old1 || old2){
                        return false;
                    }
                    old3 = 0;
                }
            }

            if(old1){
                old1--;
                new2++;
            } else if (old2){
                old2--;
                new3++;
            } else if (old3) {
                old3--;
                new3++;
            } else {
                new1++;
            }

            prevVal = num;
        }

        return !new1 && !new2;
    }
};