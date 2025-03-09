class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;
    vector<int> cur;
public:
    vector<vector<int>> subsetsWithDup(const vector<int>& nums) {
        res = {};
        this->nums = nums;
        cur = {};
        std::sort(this->nums.begin(), this->nums.end());
        calc(0);
        return res;
    }
    void calc(int i){
        if(i >= nums.size()){
            res.push_back(cur);
            return;
        }
        //we either use the current, and move on to the next, or we forbid the use of that number from now on.
        cur.push_back(nums[i]);
        calc(i + 1);
        cur.pop_back();

        //now it's forbidden, so skip while it matches.
        int match = nums[i];
        while(i < nums.size() && nums[i] == match){
            i++;
        }
        calc(i);
    }
};