class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(const int num : nums) {
            freq[num]++;
            if(freq[num] == 3) {
                return false;
            }
        }

        return true;
    }
};