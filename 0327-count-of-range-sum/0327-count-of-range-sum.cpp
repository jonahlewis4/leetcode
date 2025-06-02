class Solution {
    template <typename T>
    inline void merge(vector<T> &arr, int start1, int start2, int end1, int end2) const {
        vector<T> merged(end2 - start1);
        int mergeI = 0;

        int l = start1;
        int r = start2;
        while(l < end1 || r < end2) {
            if(r >= end2 || (l < end1 && arr[l] < arr[r])) {
                merged[mergeI] = arr[l];
                l++;
            } else {
                merged[mergeI] = arr[r];
                r++;
            }
            mergeI++;
        }


        //move mreged into arr
        for(int i = 0; i < merged.size(); i++) {
            arr[i + start1] = merged[i];
        }
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }
        //mergesort with two pointer approach.

        int ans = 0;

        for(int size = 1; size < prefix.size(); size *= 2) {
            int start1 = 0;
            int end1 = start1 + size;
            int start2 = end1;
            int end2 = start2 + size;

            while(start1 < prefix.size()){
                if(start2 >= prefix.size()){
                    break;
                }
                
                end1 = min(int(prefix.size()), end1);
                end2 = min(int(prefix.size()), end2);

                int l = start2;
                int r = start2;
                for(int i = start1; i < end1; i++){
                    //move l until >= lower
                    //move r until > upper

                    while(l < end2 && prefix[l] - prefix[i] < lower){
                        l++;
                    }

                    while(r < end2 && prefix[r] - prefix[i] <= upper) {
                        r++;
                    }

                    ans += r - l;
                }

                merge(prefix, start1, start2, end1, end2);

                start1 += 2 * size;
                end1 += 2 * size;
                start2 += 2 * size;
                end2 += 2 * size;
            }
        }


        //add all single ranges

        for(int i = 0; i < prefix.size(); i++){
            if(lower <= prefix[i] && prefix[i] <= upper) {
                ans++;
            }
        }


        return ans;
    }
};