class Solution {
private:
    vector<int> nums;
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        this->nums = nums;
        int maxDiff = nums.back() - nums[0];
        int smallestDiff = INT_MAX;
        for(int i = 0; i + 1 < nums.size(); i++){
            smallestDiff = min(smallestDiff, abs(nums[i]- nums[i+1]));
        }

        int l = smallestDiff;
        int r = maxDiff;
        int minimum = INT_MAX;
        while(l <= r){
            int m = (l + r) / 2;

            if(maxDifferencePossible(m, p)){
                //try even smaller
                r = m - 1;
                minimum = min(minimum, m);
            } else {
                l = m + 1;
            }

        }
        return minimum == INT_MAX ? 0 : minimum;
    }


    // bool maxDifferencePossible(int cand, int p) const {
    //     int count = 0;
    //     int i = 1;

    //     while(i < nums.size()) {
    //         if(nums[i] - nums[i - 1] <= cand) {
    //             count++;
    //             i += 2; // skip the next element to avoid overlapping
    //         } else {
    //             i++; // try next pair
    //         }
    //     }

    //     return count >= p;
    // }


    bool maxDifferencePossible(int cand, int p) const {
        //count number of differences smaller than candidate and verify there are at least p - 1.
        int smallerOrEqual = 0;
        for(int i = 0; i + 1 < nums.size(); i++){
            if(nums[i + 1] - nums[i] <= cand) {
                smallerOrEqual++;
                i++;
            }
        }
        
        return smallerOrEqual >= p;

    }
};