class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res;
        res += to_string(nums.front());
        if(nums.size() == 2) {
            return to_string(nums.front()) + "/" + to_string(nums.back());
        }
        if(nums.size() > 1) {

            res += "/(";

            for(int i = 1; i < nums.size(); i++) {
                res += to_string(nums[i]);
                res += "/";
            }
            res.pop_back();
            
            res += ")";
        }
        
        return res;
    }
};