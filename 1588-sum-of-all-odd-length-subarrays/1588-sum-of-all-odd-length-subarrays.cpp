class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        //[1,2,3,4]
        int total = 0;
        int oddLen = (arr.size() + 1)/2;
        for(int i = 0; i < arr.size(); i++) {
            int before = i;
            int after = arr.size() - i;

            int oddBefore = (before+1)/2;
            int evenBefore = (before)/2 + 1;
            int oddAfter = (after+1)/2;
            int evenAfter = (after)/2;

            

           

           
            int numOddSequences = evenBefore * oddAfter + oddBefore * evenAfter;
            

            //odd sequences is: even + even or odd + odd
            total += arr[i] * numOddSequences;
        }
        return total;
    }
};