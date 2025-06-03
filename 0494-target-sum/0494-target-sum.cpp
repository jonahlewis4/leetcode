class Solution {
private:
    vector<int> nums;
    int target;
    int recurse(int i, int cur) const {
        if(i == nums.size()){
            if(cur == target){
                return 1;
            }
            return 0;
        }

        int minus = recurse(i + 1, cur - nums[i]);
        int pos = recurse(i + 1, cur + nums[i]);

        return minus + pos;
    }
public:
    int findTargetSumWays(const vector<int>& _nums, int target) {
        this->target = target;
        nums = _nums;

        return recurse(0, 0);
    }
};