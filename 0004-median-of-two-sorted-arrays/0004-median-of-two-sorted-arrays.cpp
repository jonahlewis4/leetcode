class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = (nums1.size() + nums2.size());
        int halfLen = len / 2;

        if(nums1.size() > nums2.size()){
            std::swap(nums1, nums2);
        }
        //nums1 is the smaller of the two lists.
        int l = 0;
        int r = nums1.size();
        while(l <= r){
            int sM = (l + r) / 2;
            int lM = halfLen - sM;

            int sL = sM - 1 < 0 ? INT_MIN : nums1[sM - 1];
            int lL = lM - 1 < 0 ? INT_MIN : nums2[lM - 1];

            int sR = sM >= nums1.size() ? INT_MAX : nums1[sM];
            int lR = lM >= nums2.size() ? INT_MAX : nums2[lM];

            if(lL > sR){
                l = sM + 1;
            } else if (sL > lR){
                r = sM - 1;
            } else {
                if(len % 2 == 0){
                    return (std::max(sL, lL) + std::min(sR, lR)) / 2.0;
                } else {
                    return std::min(sR, lR);
                }
            }
        }
        return -1;
        
    }
};