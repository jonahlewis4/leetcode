class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int first = nums[l];
            if(target == first) {
                return l;
            }
            int m = (l + r) / 2;
            int mid = nums[m];
            if(mid == target) {
                return m;
            }

            if(mid < first) {
                if (target > first || target < mid) {
                    //go left
                    r = m - 1;
                } else {
                    //go right
                    l = m + 1;
                }
            } else {
                if(target < first || target > mid) {
                    //go right
                    l = m + 1;
                } else {
                    //go left
                    r = m - 1;
                }
            }

        }
        return -1;
    }
};