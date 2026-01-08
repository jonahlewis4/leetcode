class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        int diff = max - min;
        diff -= k * 2;  

        // cout<<"minimum element: "<<min<<endl;
        // cout<<"maximum element: "<<max<<endl;

        // cout<<"difference: "<<max - min<<endl;
        // cout<<"adjusted difference: "<<diff<<endl;

        return std::max(0, diff);
    }
};