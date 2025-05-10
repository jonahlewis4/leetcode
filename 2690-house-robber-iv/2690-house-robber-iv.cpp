class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        //find the SMALLEST item that can be formed. 
        int res = r;
        while(l <= r){
            int m = ( l + r ) / 2;
            bool valid = canBeFormed(m, nums, k);

            //if valid, try to find a smaller one.
            if(valid) {
                r = m - 1;
                res = m;
            } else /* if invalid, try to find a larger one */{
                l = m + 1;
            }
        }
        return res;
    }

    bool canBeFormed(int capability, const vector<int> &nums, int k){
        int i = 0;
        int nonAdjacent = 0;
        while(i < nums.size()){
            if(nums[i] <= capability){
                nonAdjacent++;
                i += 2;
            } else {
                i++;
            }
        }

        return nonAdjacent >= k;
    }
};