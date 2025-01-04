class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int maxL = height[l];
        int maxR = height[r];
        int water = 0;
        while( l <= r ){
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);
            int moreWater;
            if(maxL < maxR){
                moreWater = maxL - height[l];
                l++;
            } else {
                moreWater = maxR - height[r];
                r--;
            }
            if(moreWater > 0){
                water += moreWater;
            }
        }
        return water;
    }
};