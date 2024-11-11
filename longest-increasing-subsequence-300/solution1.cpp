//
// Created by jonahnlewis on 11/10/24.
//

//video: https://youtu.be/on2hvxBXJH4?si=AZC7wlXoj1whLQ_5

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> subsequence;

        //find lower bound of each element in nums in the subsequence.
        //if position is in, set subsequence[i] top arr[i]
        //if not in push back arr[i]
        for(int i = 0; i < nums.size(); i++){
            int pos = std::lower_bound(subsequence.begin(), subsequence.end(), nums[i]) - subsequence.begin();
            if(pos >= subsequence.size()){
                subsequence.push_back(nums[i]);
            }
            else if (pos >= 0){
                subsequence[pos] = nums[i];
            }
        }
        return subsequence.size();
    }
};