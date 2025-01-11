class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;

        std::unordered_map<int, vector<int>> set;

        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            set[nums[i]].push_back(i);
        }

        int maxOutlier = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int twiceGoal = sum - nums[i];
            if(twiceGoal % 2 == 0 && set.find(twiceGoal / 2) != set.end()){
                for(const int num : set[twiceGoal / 2]){
                    if(num != i){
                        maxOutlier = max(maxOutlier, nums[i]);
                    }
                }
            }
        }

        return maxOutlier;

      

        
    }
};