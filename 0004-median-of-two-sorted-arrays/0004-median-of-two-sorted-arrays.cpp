class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int n = nums1.size();
        int m = nums2.size();

        int totalElem = n + m;
        int rightCount = totalElem / 2;
        int leftCount = totalElem - rightCount;

        int l = 0;
        int r = n;
        while(l <= r) {
            //m will be the first element on the right
            int numLeft1 = (l + r) / 2;
            int numLeft2 = leftCount - numLeft1;
            
            int l1 = numLeft1 - 1 >= 0 ? nums1[numLeft1 - 1] : INT_MIN;
            int l2 = numLeft2 - 1 >= 0 ? nums2[numLeft2 - 1] : INT_MIN;
            int r1 = numLeft1 < n ? nums1[numLeft1] : INT_MAX;
            int r2 = numLeft2 < m ? nums2[numLeft2] : INT_MAX ;

            if(l1 <= r2 && l2 <= r1){
                if(totalElem % 2 == 1) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                r = numLeft1 - 1;
            } else {
                l = numLeft1 + 1;
            }
        }

        return -1;
    }
};