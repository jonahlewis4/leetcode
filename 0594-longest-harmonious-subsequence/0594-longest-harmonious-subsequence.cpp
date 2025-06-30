class Solution {
public:
    int findLHS(const vector<int>& nums) {
        unordered_map<int, int> freq;
        for(const auto & num : nums) {
            freq[num]++;
        }

        int longestLength = 0;
        for(const auto & num : nums) {
            int thisIsTheBigger = freq[num] + freq[num - 1];
            if(thisIsTheBigger == freq[num]){
                thisIsTheBigger = 0;
            }
            int thisIsTheSmaller = freq[num] + freq[num + 1];
            if(thisIsTheSmaller == freq[num]) {
                thisIsTheSmaller = 0;
            }
            longestLength = max({longestLength, thisIsTheBigger, thisIsTheSmaller});
        }
        return longestLength;
    }
};