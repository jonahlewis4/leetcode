class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i < arr1.size(); i++) {
            int num1 = arr1[i];
            int small = num1 - d;
            int big = num1 + d;
            
            //count numbers in range small, big
            auto left = lower_bound(arr2.begin(), arr2.end(), small);
            auto right = upper_bound(arr2.begin(), arr2.end(), big);


            int diff = right - left;
            if(diff == 0) {
                res++;
            }
        }

        return res;
    }
};