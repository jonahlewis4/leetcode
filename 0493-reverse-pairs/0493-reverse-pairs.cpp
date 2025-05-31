class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int pairs = 0;

        for(int size = 1; size <  nums.size(); size *= 2){
            int start1 = 0;
            int end1 = start1 + size;
            int start2 = end1;
            int end2 = start2 + size;

            while(start1 < nums.size()){
                if(start2 >= nums.size()){
                    break;
                }

                if(end2 > nums.size()){
                    end2 = nums.size();
                }

                //forEach in right window, search to find number less than num to Beat

                int j = start2;
                for(int i = start1; i < end1; i++){
                    while(j < end2 && nums[i] > (long long)nums[j] * 2){
                        // pairs++;
                        j++;
                    }
                    pairs += j - start2;
                }

                //merge left and right subarrays
                vector<int> merged(end2 - start1);
                int mergeI = 0;
                int l1 = start1;
                int l2 = start2;
                while(l1 < end1 || l2 < end2) {
                    if(l2 >= end2 || (l1 < end1 && nums[l1] < nums[l2])){
                        merged[mergeI] = nums[l1];
                        l1++;
                    } else {
                        merged[mergeI] = nums[l2];
                        l2++;
                    }
                    mergeI++;
                }
                
                for(int i = 0; i < merged.size(); i++){
                    nums[start1 + i] = merged[i];
                }

                //update bounds
                start1 += size * 2;
                end1 += size * 2;
                start2 += size * 2;
                end2 += size * 2;
            }
        }

        return pairs;
    }
};