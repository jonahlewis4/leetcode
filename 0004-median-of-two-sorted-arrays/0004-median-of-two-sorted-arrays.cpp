class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            std::swap(nums1, nums2);
        }

        int halfCount = (nums1.size() + nums2.size()) / 2;

        int l = 0;
        int r = nums1.size();

        while (l <= r)  {
            int m = (l + r) / 2;
            int m2 = halfCount - m;

            int l1 = m > 0 ? nums1[m - 1] : INT_MIN;
            int l2 = m2 > 0 ? nums2[m2 - 1] : INT_MIN;
            int r1 = m < nums1.size() ? nums1[m] : INT_MAX;
            int r2 = m2 < nums2.size() ? nums2[m2] : INT_MAX;
            if(l1 <= r2 && l2 <= r1){
                
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return ( double(max(l1, l2)) + (min(r1, r2)) ) / 2;
                }
                return min(r1, r2);
            }
            if(l1 > r2){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;      
    }
};