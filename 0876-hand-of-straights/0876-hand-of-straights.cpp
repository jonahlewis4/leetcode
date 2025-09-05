class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> nums;
        for(const auto & num : hand) {
            nums[num]++;
        }

        int numGroups = hand.size() / groupSize;
        for(int groupNum = 0; groupNum < numGroups; groupNum++){
            int firstInGroup = nums.begin()->first;
            nums[firstInGroup]--;
            if(nums[firstInGroup] == 0) {
                nums.erase(firstInGroup);
            }

            for(int i = 1; i < groupSize; i++){
                int desired = firstInGroup + i;
                if(nums.find(desired) == nums.end()){
                    return false;
                }
                nums[desired]--;
                if(nums[desired] == 0) {
                    nums.erase(desired);
                }
            }
        }

        return true;
    }
};