class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> lexi(nums.size());
        for(int i = 0; i < nums.size(); i++){
            lexi[i] = to_string(nums[i]);
        }
        sort(lexi.begin(), lexi.end(), [](const string & a, const string & b){
            return a + b < b + a;
        });

        string res = "";
        for(int i = lexi.size() - 1; i>=0; i--){
            res += lexi[i];
        }
        reverse(res.begin(), res.end());
        while(res.size() > 1 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};