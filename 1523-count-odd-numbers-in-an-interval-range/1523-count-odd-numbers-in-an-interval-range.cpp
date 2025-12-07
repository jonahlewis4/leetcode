class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low;
        
        return diff/2 + ((low & 1) | (high & 1));
    }
};