class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++){
            int cand = numbers[i];
            int compliment = target - cand;
            int j = binarySearch(numbers, compliment);
            if(i == j){
                int left = i - 1 >= 0 ? numbers[i - 1] : INT_MIN;
                int right = i + 1 < numbers.size() ? numbers[i + 1] : INT_MAX;

                if(left == compliment){
                    return {i + 1, i - 1 + 1};
                }
                if(right == compliment){
                    return {i + 1, i + 1 + 1};
                }

                return {};
            } else if (j >= 0){
                return {i + 1, j + 1};
            }
        }
        return {};
    }
    int binarySearch(vector<int> & nums, int n){
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == n){
                return m;
            } else if(nums[m] < n){
                l = m + 1;
            } else if(nums[m] > n){
                r = m - 1;
            }
            
        }
        return -1;
    }
};