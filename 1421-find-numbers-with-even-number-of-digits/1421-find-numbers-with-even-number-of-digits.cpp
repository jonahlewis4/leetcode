class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto & num : nums){
            int len = 0;
            while(num > 0){
                num /= 10;
                len++;
            }
            if(len % 2 == 0){
                res++;
            }
        
        }
        return res;
    }
};