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

                //forEach in right window, binary search to find all of the ones in the left that are > 2 * right value

                for(int i = start2; i < end2; i++){
                    long long rightVal = nums[i];
                    long long numToBeat = 2 * rightVal;

                    
                    auto start1Itr = nums.begin() + start1;
                    auto end1Itr = nums.begin() + end1;

                    //count number of elements in left which are greater than numToBeat
                    auto firstNumGreaterItr = upper_bound(start1Itr, end1Itr, numToBeat);
                    int amountGreater = end1Itr - firstNumGreaterItr;
                    pairs += amountGreater;    
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