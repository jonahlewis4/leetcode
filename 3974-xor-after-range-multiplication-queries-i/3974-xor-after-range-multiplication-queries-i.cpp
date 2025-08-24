class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       for(const auto & query : queries) {
           int li = query[0];
           int ri = query[1];
           int ki = query[2];
           int vi = query[3];

           for(int idx = li; idx <= ri; idx += ki) {
               nums[idx] = ((long long)nums[idx] * vi) % ((int)1e9 + 7);
           }
       } 
        int zor = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            zor ^= nums[i];
        }
        return zor;
    }
};