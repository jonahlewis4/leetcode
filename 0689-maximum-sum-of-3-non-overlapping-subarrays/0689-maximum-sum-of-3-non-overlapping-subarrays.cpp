class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

      

        int kSum = 0;
        vector<int> sizes(nums.size() - k + 1);

        for(int i = 0; i < nums.size(); i++){
            kSum += nums[i];
            if(i + 1 - k >= 0){
                sizes[i + 1 - k] = kSum;
                kSum -= nums[i + 1 - k];
            }
        }
        vector<int> largestFromI(sizes.size());
        largestFromI[largestFromI.size() - 1] = sizes.size() - 1;
        for(int i = largestFromI.size() - 2; i >= 0; i--){
            int thisSize = sizes[i];
            int runningSize = sizes[largestFromI[i + 1]];
            int largestIdx = -1;
            if(thisSize >= runningSize){
                largestIdx = i;
            } else {
                largestIdx = largestFromI[i + 1];
            }
            largestFromI[i] = largestIdx;
        }

        //find the 2 closest for every non overlapping

        int maxSum = INT_MIN;
        vector<int> res;
        for(int firstStart = 0; firstStart < sizes.size(); firstStart++){
            int firstSize = sizes[firstStart];
            for(int secondStart = firstStart + k; secondStart < sizes.size(); secondStart++){
                int secondSize = sizes[secondStart];


                int firstThirdStart = secondStart + k;
                if(firstThirdStart >= sizes.size()){
                    continue;
                }
                int thirdStart = largestFromI[firstThirdStart];
                if(thirdStart >= sizes.size()){
                    continue;
                }
                int thirdSize = sizes[thirdStart];
                int sum = firstSize + secondSize + thirdSize;
                if(sum > maxSum){
                    res = {firstStart, secondStart, thirdStart};
                    maxSum = sum;
                }
            }
        }

        return res;


    }
};