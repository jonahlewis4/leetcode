class Memo {
private:
    vector<int> sizes;
    vector<int> nums;
    int k;
    vector<vector<int>> dp;
    int maxSumFrom(int start, int splitNumber) {
            if(start + k > nums.size() || splitNumber >= 3){
                return 0;
            }
            
            if(dp[start][splitNumber] != -1){
                return dp[start][splitNumber];
            }
            //use this one or skip it

            int use = sizes[start] + maxSumFrom(start + k, splitNumber + 1);
            int skip = maxSumFrom(start + 1, splitNumber);
            dp[start][splitNumber] = max(use, skip);
            return max(use, skip);
        }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
      

        int kSum = 0;
        sizes.resize(nums.size() - k + 1);

        for(int i = 0; i < nums.size(); i++){
            kSum += nums[i];
            if(i + 1 - k >= 0){
                sizes[i + 1 - k] = kSum;
                kSum -= nums[i + 1 - k];
            }
        }

        dp.resize(nums.size() - k + 1, vector<int>(3, -1));




        vector<int> starts;
        int i = 0; 
        while(i <= nums.size() - k && starts.size() < 3){
            int use = sizes[i] + maxSumFrom(i + k, starts.size() + 1);
            int skip = maxSumFrom(i + 1, starts.size());

            if(use >= skip) {
                starts.push_back(i);
                i += k;
            } else {
                i++;
            }


        }        
        
        return starts;

    }
};

class Tabulation{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        vector<int> sizes(nums.size() - k + 1);
        int kSum = 0;
        for(int i = 0; i < nums.size(); i++){
            kSum += nums[i];
            if(i + 1 - k >= 0){
                sizes[i + 1 - k] = kSum;
                kSum -= nums[i + 1 - k];
            }
        }

        
        struct dpItem{
            int sum;
            int index;
        };
        vector<vector<dpItem>> dp(4, vector<dpItem>(nums.size() + 1, {
            .sum = 0,
            .index = -1,
        }));

        for(int r = 2; r >= 0; r--){
            for(int c = nums.size() - k; c >= 0; c--){
                dpItem use = {
                    .sum = sizes[c] + dp[r + 1][c + k].sum,
                    .index = c
                };
                dpItem skip = dp[r][c + 1];

                
                if(use.sum >= skip.sum){
                    dp[r][c] = use;
                } else {
                    dp[r][c] = skip;
                }
            }
        }

        vector<int> starts;
        int nextPossibleStart = 0;
        for(int i = 0; i < 3; i++){
            starts.push_back(dp[i][nextPossibleStart].index);
            nextPossibleStart = starts.back() + k;
        }
        
        return starts;
    }


};

class ThreePointer {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) const {
        vector<int> sumFrom(nums.size() - k + 1, 0);

        int windowSum = 0;
        for(int i = 0; i < nums.size(); i++){
            windowSum += nums[i];
            if(i - k + 1 >= 0){
                sumFrom[i - k + 1] = windowSum;
                windowSum -= nums[i - k + 1];
            }
        }


        vector<int> iMaxSumBefore(sumFrom.size());
        
        int maxSumI = 0;
        for(int i = 0; i < iMaxSumBefore.size(); i++){
            int newSum = sumFrom[i];
            if(newSum > sumFrom[maxSumI]){
                maxSumI = i;
            }
            iMaxSumBefore[i] = maxSumI;
        }

        vector<int> iMaxSumAfter(sumFrom.size());
        maxSumI = iMaxSumAfter.size() - 1;
        for(int i = iMaxSumAfter.size() - 1; i >= 0; i--){
            int newSum = sumFrom[i];
            if(newSum >= sumFrom[maxSumI]){
                maxSumI = i;
            }
            iMaxSumAfter[i] = maxSumI;
        }

        vector<int> best;

        int maxSum = -1;
        for(int m = k; m + k < sumFrom.size(); m++){
            int l = m - k;
            int r = m + k;

            int oL = iMaxSumBefore[l];
            int oR = iMaxSumAfter[r];

            int lSum = sumFrom[oL];
            int rSum = sumFrom[oR];
            int mSum = sumFrom[m];

            int sum = lSum + rSum + mSum;

            if(sum > maxSum){
                maxSum = sum;
                best = {oL, m, oR};
            }
        }




        return best;
    }
};

class SlidingWindow{
public:
    vector<int> maxSumOfThreeSubarrays(const vector<int>& nums, int k) const {
        int l1 = 0;
        int sum1 = 0;
        int bestSum1;
        vector<int> bestIndex1;
        for(int i = l1; i < l1 + k; i++){
            sum1 += nums[i];
        }
        bestSum1 = sum1;
        bestIndex1.push_back(l1);

        int l2 = l1 + k;
        int sum2 = 0;
        int bestSum2;
        vector<int> bestIndex2 = bestIndex1;
        for(int i = l2; i < l2 + k; i++){
            sum2 += nums[i];
        }
        bestSum2 = sum2 + bestSum1;
        bestIndex2.push_back(l2);

        int l3 = l2 + k;
        int sum3 = 0;
        int bestSum3;
        vector<int> bestIndex3 = bestIndex2;
        for(int i = l3; i < l3 + k; i++){
            sum3 += nums[i];
        }
        bestSum3 = sum3 + bestSum2;
        bestIndex3.push_back(l3);

        sum1 -= nums[l1];
        sum2 -= nums[l2];
        sum3 -= nums[l3];

        l1++;
        l2++;
        l3++;
        while(l3 + k - 1 < nums.size()){
            sum1 += nums[l1 + k - 1];
            sum2 += nums[l2 + k - 1];
            sum3 += nums[l3 + k - 1];

            if(sum1 > bestSum1){
                bestIndex1[0] = l1;
                bestSum1 = sum1;
            }


            if(sum2 + bestSum1 > bestSum2) {
                bestIndex2 = bestIndex1;
                bestIndex2.push_back(l2);
                bestSum2 = bestSum1 + sum2;
            }

            if(sum3 + bestSum2 > bestSum3){
                bestIndex3 = bestIndex2;
                bestIndex3.push_back(l3);
                bestSum3 = bestSum2 + sum3;
            }

            sum1 -= nums[l1];
            sum2 -= nums[l2];
            sum3 -= nums[l3];
            l1++;
            l2++;
            l3++;

        }

        return bestIndex3;
    }
};

class Solution{
public:

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        return SlidingWindow().maxSumOfThreeSubarrays(nums, k);
    }

};