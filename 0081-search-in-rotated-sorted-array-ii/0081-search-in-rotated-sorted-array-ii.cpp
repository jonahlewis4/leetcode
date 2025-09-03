class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(target == nums[0]) {
            return true;
        }

        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            int mid = nums[m];

            int first = nums[l];
            if(first == target) {
                return true;
            }
            if(mid == target) {
                return true;
            }

            if(mid < first) {
                if (target > first || target < mid) {
                    //go left
                    r = m - 1;
                } else {
                    //go right
                    l = m + 1;
                }
            } else if (mid > first){
                if(target < first || target > mid) {
                    //go right
                    l = m + 1;
                } else {
                    //go left
                    r = m - 1;
                }
            } else {
                l++;
            }

        }
        return false;
    }
};