class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums1.size()){
            std::swap(nums1, nums2);
        }
        int halfLen = (nums1.size() + nums2.size()) / 2;

        int l = 0;
        int r = nums2.size();
        while(l <= r){
            int m = (l + r) / 2;
            int l2 = m - 1 >= 0 ? nums2[m - 1] : INT_MIN;
            int r2 = m < nums2.size() ? nums2[m] : INT_MAX;
            int m1 = halfLen - m;
            int l1 = m1 - 1 >= 0 ? nums1[m1 - 1] : INT_MIN;
            int r1 = m1 < nums1.size() ? nums1[m1] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                //return ans;
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return ((double)max(l1, l2) + min(r2, r1))/2;
                } else {
                    return min(r1, r2);
                }
            } else {
                if(l2 > r1){
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }


        }
        return -1;
    }
};