class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        while(max(x,y) > 0) {
            int xDig = x % 2;
            int yDig = y % 2;
            if(xDig != yDig) {
                diff++;
            }
            x >>=1;
            y >>=1;
        }
        return diff;
    }
};