class Solution {

    
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        lis.front() = 1;
        int best = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]){
                    lis[i] = max(lis[i], lis[j] + 1);
                    best = max(lis[i], best);
                }
            }
        }

        vector<unsigned int> count(nums.size(), 0);
        count.front() = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++){
               
                if(lis[j] == lis[i] - 1 && nums[j] < nums[i]){
                    count[i] += count[j];
                }
            }
            if(lis[i] == 1) {
                count[i] = 1;
            }
        }

        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int len = lis[i];
            if(len == best) {
                res += count[i];
            }
        }

        return res;
    }
};