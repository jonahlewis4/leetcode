class Solution {
public:
    int maxArea(vector<int>& height) {
        int best = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r) {
            int width = r - l;
            int h1 = height[l];
            int h2 = height[r];
            int height = min(h1, h2);
            int area = height * width;
            best = max(area, best);
            if(h1 < h2) {
                l++;
            } else {
                r--;
            }
        }
        return best;
    }
};