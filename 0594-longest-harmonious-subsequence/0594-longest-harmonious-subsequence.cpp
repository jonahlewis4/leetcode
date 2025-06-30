class Solution {
public:
    int findLHS(const vector<int>& nums) {
        unordered_map<int, int> freq;
        for(const auto & num : nums) {
            freq[num]++;
        }

        int longestLength = 0;
        for(const auto & [num, _] : freq) {
            if(freq.find(num - 1) != freq.end()){
                longestLength = max(longestLength, freq[num] + freq[num - 1]);
            }
            if(freq.find(num + 1) != freq.end()){
                longestLength = max(longestLength, freq[num] + freq[num + 1]);
            }
        }
        return longestLength;
    }
};