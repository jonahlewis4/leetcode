class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> found(n + 1, false);

        vector<int> res(2);

        for(const int num : nums) {
            if(found[num]){
                res.front() = num;
            }

            found[num] = true;
        }

        for(int i = 1; true; i++) {
            if(!found[i]){
                res.back() = i;
                return res;
            }
        }
    }
};