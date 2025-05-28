class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long pairs = 0;
        int n = nums1.size();
        vector<int> diff(nums1.size());
        for(int i = 0; i < n; i++){
            diff[i] = nums1[i] - nums2[i];
        }

        sort(diff.begin(), diff.end());
        for(int i = 0; i < diff.size(); i++){
            int d = diff[i];

            int target = 0 - d; 
            auto it = upper_bound(diff.begin(), diff.end(), target);
            
            auto curItr = diff.begin() + i;
            if(curItr >= it){
                it = next(curItr);
            }
            int dist = diff.end() - it;

            pairs += dist;
        }

        
        return pairs;
    }
};