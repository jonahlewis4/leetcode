class Solution {
    static inline vector<int> set = {
        0b1, 
        0b11,
        0b111,
        0b1111,
        0b11111,
        0b111111,
        0b1111111,
        0b11111111,
        0b111111111,
        0b1111111111
    };
public:
    int smallestNumber(int n) {
        return *lower_bound(set.begin(), set.end(), n);
    }
};