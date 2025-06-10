class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(const auto & c : s){
            freq[c]++;
        }

        int smallestOdd = INT_MAX;
        int largestOdd = INT_MIN;
        int smallestEven = INT_MAX;
        int largestEven = INT_MIN;

        for(const auto & p : freq) {
            int count = p.second;
            if(count % 2 == 0){
                smallestEven = min(count, smallestEven);
                largestEven = max(count, largestEven);
            } else {
                smallestOdd = min(count, smallestOdd);
                largestOdd = max(count, largestOdd);
            }
        }

        return largestOdd - smallestEven;
    }
};