class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        //find largest product which is rank k or less.
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        long long front1 = nums1.front();
        long long front2 = nums2.front();
        long long back1 = nums1.back();
        long long back2 = nums2.back();

        long long corner1 = front1 * front2;
        long long corner2 = front1 * back2;
        long long corner3 = front2 * back1;
        long long corner4 = back1 * back2;

        long long minProduct = min({
            corner1, corner2, corner3, corner4
        });
        long long maxProduct = max({
            corner1, corner2, corner3, corner4
        });

        long long l = minProduct;
        long long r = maxProduct;

        long long best = minProduct;
        
        while(l <= r) {
            long long m = (l + r) / 2;
            long long rank = Rank(nums1, nums2, m);
            if(rank > k){
                r = m - 1;
            } else {
                best = m;
                l = m + 1;
            }
        }
        return best;   
    }

    long long Rank(vector<int>& nums1, vector<int>& nums2, long long prod) const {
        long long rank = 1;
        for(const auto & num : nums1){
            int numSmaller = numElementsSmaller(nums2, num, prod);
            rank += numSmaller;
        }  
        return rank;
    }

    static int numElementsSmaller(vector<int>& nums2, int num, long long prod) {
        if(num == 0) {
            if(prod <= 0) {
                return 0;
            }
            return nums2.size();
        }

        if(num < 0) {
            long long target = floor((double) prod / num);
            const auto & itr = upper_bound(nums2.begin(), nums2.end(), target);
            return nums2.end() - itr;
        }

        long long target = ceil((double) prod / num);
        const auto & itr = lower_bound(nums2.begin(), nums2.end(), target);
        return itr - nums2.begin();
    }

};