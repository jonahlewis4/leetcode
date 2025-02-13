class Solution {
private:
    string hash(vector<int> & v) {
        string res = "";
        for(const auto & i : v){
            res += to_string(i) + ",";
        }
        return res;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        unordered_set<string> set;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int l = j + 1;
                int r = nums.size() - 1;

                long newTarget = (long)target - (long)nums[i] - (long)nums[j];
                while(l < r){
                    if(nums[l] + nums[r] > newTarget){
                        r--;
                    } else if (nums[l] + nums[r] < newTarget){
                        l++;
                    } else {
                        vector<int> match = {nums[i], nums[j], nums[l], nums[r]};
                        if(set.find(hash(match)) == set.end()){
                            set.insert(hash(match));
                            res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        }
                        while(l + 1 < r && nums[l] == nums[l + 1]){
                            l++;
                        }
                        l++;
                    }
                }
            }
        }
        return res;
    }
};