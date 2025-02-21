class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        //sort every element.
        std::sort(nums.begin(), nums.end());
        //binary search based on the distance
        int l = 0;
        int r = *std::max_element(nums.begin(), nums.end()) - *std::min_element(nums.begin(), nums.end());
        while(l < r){
            int m = (l + r) / 2;
            int pairs = numPairs(nums, m);
            //if the number of pairs < k, l = m + 1
            if (pairs < k){
                l = m + 1;
            } 
            //if the number of pairs > k, r = m. Don't set to m - 1 because it could represent the upper bound.
            //imagine something like  1,2,3,3,3,3,3,3,3, as the distances, and k is 4. There are 9 pairs where the distance is 3 or less, but k could still be equal to 3, so if we calculate that the number of pairs is greater than k, we set r to m and if none of the smaller values end up reaching it we will exit when l reaches r at 3.
            else {
                r = m;
            }
        }
        return l;
    }

    //numPairs calculates the number of pairs with distance less than or equal to distance.
    //nums must be already sorted.
    int numPairs(const std::vector<int> & nums, int distance){
        //sliding window:

        //if rVal - lVal is less than or equal distance, every value between rVal and lVal is added. Then increase r
        //otherwise increase l to try to decrease rVal - lVal
        int l = 0;
        int r = 0;
        int pairs = 0;
        while(r < nums.size()){
            int rVal = nums[r];
            int lVal = nums[l];
            if(rVal - lVal <= distance){
                pairs += r - l;
                r++;
            } else {
                l++;
            }
        }
        return pairs;
    
    }
};