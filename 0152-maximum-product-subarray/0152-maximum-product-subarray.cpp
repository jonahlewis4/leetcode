class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int neg = 1;
        int pos = 1;

        int res = INT_MIN;

        for(int i = 0; i < nums.size(); i++){


            int oldPos = pos;
            int val = nums[i];


            pos = max({pos * val, neg * val, val});
            neg = min({oldPos * val, neg * val, val});
            res = max({res, pos, neg});
        }

        return res;
    }
};