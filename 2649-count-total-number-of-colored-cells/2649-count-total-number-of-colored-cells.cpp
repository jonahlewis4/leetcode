class Solution {
public:
    long long coloredCells(int n) {
        long long nL = static_cast<long long>(n);
        return ((nL * 4) * (nL - 1)) / 2 + 1;
    }
};