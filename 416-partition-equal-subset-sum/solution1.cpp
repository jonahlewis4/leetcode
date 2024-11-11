//
// Created by jonahnlewis on 11/10/24.
//

//video: https://youtu.be/IsvocB5BJhw?si=6nuxL1ClypDQEVu4
//comment: Algorithm from neetcode, he does it in python

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //determine if we can arrive at sum / 2 through a subset

        //create a set of all the possible sums and loop through.

        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        //odd sum impossible
        if(sum % 2 == 1){
            return false;
        }

        int target = sum / 2;

        //now that we have the sum, loop through and add to a set
        std::unordered_set<int> subSums;
        for(int i = 0; i < nums.size(); i++){
            std::vector<int> newSums;
            newSums.push_back(nums[i]);
            for(const auto & subSum : subSums){
                int newSubSum = subSum + nums[i];
                newSums.push_back(newSubSum);
            }
            //add all the newSums to the set
            for(const auto & newSum : newSums){
                subSums.insert(newSum);
            }
            if(subSums.find(target) != subSums.end()){
                return true;
            }
        }
        return false;
    }

};