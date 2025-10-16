class Solution {
    int helper(const vector<int>&a, int aL, int aR, const vector<int>& b, int bL, int bR, int k) {
        int aSize = aR - aL + 1;
        int bSize = bR - bL + 1;

        if(aSize <= 0) {
            return b[bL + k - 1];
        }
        if(bSize <= 0) {
            return a[aL + k - 1];
        }
        if(k == 1){
            return min(a[aL], b[bL]);
        }

        int kHalf = k / 2;
        int aI = aL + min(aSize, kHalf) - 1;
        int bI = bL + min(bSize, kHalf) - 1;
        int aVal = a[aI];
        int bVal = b[bI];

        if(aVal < bVal) {
            int knownSmaller = aI - aL + 1;
            
            int newK = k - knownSmaller;
            return helper(a, aI + 1, aR, b, bL, bR, newK);
        } else {
            int knownSmaller = bI - bL + 1;
            int newK = k - knownSmaller;

            return helper(a, aL, aR, b, bI + 1, bR, newK);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int count = n + m ;
        if(count % 2 == 1) {
            return helper(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, count / 2 + 1);
        } else {
            int first = helper(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, count / 2);
            int second = helper(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, count / 2 + 1);
            return (first + second) / 2.0;
        }
    }
};