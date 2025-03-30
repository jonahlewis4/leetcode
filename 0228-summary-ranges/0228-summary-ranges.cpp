class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
 
        int l = 0;
        int r = 1;
        vector<string> res;
        while(r <= nums.size()){
            if(r == nums.size() || int(nums[r]) != int(nums[r - 1] + 1)){
                res.push_back(rangeString(nums[l], nums[r - 1]));
                l = r;
            }
            r++;
        }
        return res;
    }

    string rangeString(int lVal, int rVal){
        if(lVal == rVal){
            return to_string(lVal);
        }
        return to_string(lVal) + "->" + to_string(rVal);
    }
};