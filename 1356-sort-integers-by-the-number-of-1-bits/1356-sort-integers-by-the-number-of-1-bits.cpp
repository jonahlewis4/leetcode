class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](
            const int a,
            const int b
        ){
            int aBits = __builtin_popcount(a);
            int bBits = __builtin_popcount(b);

            if(aBits < bBits){
                return true;
            }
            if(aBits > bBits) {
                return false;
            }

            return a < b;
        });

        return arr;
    }
};