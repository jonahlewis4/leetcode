class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int g = gcd(x,y);
        return target % g == 0 && x + y >= target;
    }
};