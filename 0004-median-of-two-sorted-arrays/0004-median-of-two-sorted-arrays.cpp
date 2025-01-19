class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        

        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }


        
        int len = (nums1.size() + nums2.size());
        int halfLen = len / 2;

        int l = 0; 
        int r = nums1.size();
        while(l <= r){
            int botM = (l + r) / 2;
            int topM = halfLen - botM;
            int botL = botM - 1 >= 0 ? nums1[botM - 1] : INT_MIN;
            int topL = topM - 1 >= 0 ? nums2[topM - 1] : INT_MIN;
            
            int botR = botM < nums1.size() ? nums1[botM] : INT_MAX;
            int topR = topM < nums2.size() ? nums2[topM] : INT_MAX;

            if(botL <= topR && topL <= botR){
                if(len % 2 == 0){
                    return (max(botL, topL) + min(botR, topR)) / 2.0;
                } else {
                    return min(botR, topR);
                }
            } else if(botL > topR){
                r = botM - 1;
            } else {
                l = botM + 1;
            }
        }
        return -1;
    }
};