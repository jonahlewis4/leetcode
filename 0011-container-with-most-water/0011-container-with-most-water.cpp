class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            int area = min(height[l], height[r]) * (r - l);
            maxArea = max(area, maxArea);
            if(height[l] > height[r]){
                r--;
            } else {
                l++;
            }
        }
        return maxArea;
    }
};