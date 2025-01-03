class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0;
        int p2 = 0;
        
        vector<int> res(nums1.size());
        while(p1 < m || p2 < n){
            if(p1 >= m || p2 < n && nums2[p2] < nums1[p1]){
                res[p1 + p2] = nums2[p2];
                p2++;
            } else {
                res[p1 + p2] = nums1[p1];
                p1++;
            }
        }
        nums1 = res;
    }
};