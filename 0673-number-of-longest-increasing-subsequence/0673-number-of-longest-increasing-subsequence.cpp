class Solution {

    
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        vector<unsigned int> count(nums.size(), 1);
        int best = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]){
                    if(lis[j] + 1 > lis[i]){
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    } else if (lis[j] == lis[i] - 1) {
                        count[i] += count[j];
                    }
                }
            }
            best = max(best, lis[i]);
        }

        
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(lis[i] == best) {
                res += count[i];
            }
        }

        return res;
    }
};