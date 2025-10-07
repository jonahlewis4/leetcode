class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());

        if(maxVal - minVal == 0) {
            return 0;
        }
        int bucketSize = ceil((double)(maxVal - minVal) / (n - 1));
        int bucketCount = (double)(maxVal - minVal) / (bucketSize) + 1;
        vector<pair<int, int>> buckets(bucketCount, {
            INT_MAX,
            INT_MIN
        });
        for(const int i : nums) {
            int iAdjusted = i - minVal;

            int bucketI = iAdjusted / (bucketSize);
            buckets[bucketI] = {
                min(buckets[bucketI].first, i),
                max(buckets[bucketI].second, i),
            };
        } 

        int lastMax = INT_MIN;
        int largestGap = 0;
        for(auto & [s, l] : buckets) {
            if(lastMax != INT_MIN && s != INT_MAX) {
                int gap = s - lastMax;
                largestGap = max(gap, largestGap);
            }
            
            lastMax = max(l, lastMax);        
        }
        
        return largestGap;
    }
};