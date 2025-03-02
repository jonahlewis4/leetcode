class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = INT_MIN / 2;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = abs(target - sum);
                    if(diff < abs(target - closestSum)){
                        closestSum = sum;
                    }
                }
            }
        }
        return closestSum;
    }
};