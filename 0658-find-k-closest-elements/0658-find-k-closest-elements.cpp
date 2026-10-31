class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;
        while(l < r) {
            int m = l + (r-l)/2;
            int nextEnd = arr[m + k];

            bool xOnRight = (x - arr[m]) > (arr[m+k] - x);
            if(xOnRight){
                l = m + 1;
            } else {
                r = m;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};