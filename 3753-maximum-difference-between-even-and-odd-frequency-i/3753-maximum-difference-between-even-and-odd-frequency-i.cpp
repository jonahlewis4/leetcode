class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(const auto & c : s){
            freq[c]++;
        }

        int largestOdd = INT_MIN;
        int smallestEven = INT_MAX;

        for(const auto & p : freq) {
            int count = p.second;
            if((count & 1) == 0){
                smallestEven = min(count, smallestEven);
            } else {
                largestOdd = max(count, largestOdd);
            }
        }

        return largestOdd - smallestEven;
    }
};