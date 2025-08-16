class Solution {
public:
    long long coloredCells(int n) {
        long long nL = static_cast<long long>(n);
        return ((nL * 2) * (nL - 1)) + 1;
    }
};