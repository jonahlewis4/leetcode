class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int smallest = INT_MAX;
        int secSmallest = INT_MAX;
        int biggest = INT_MIN;
        int secBiggest = INT_MIN;
        int thirdBiggest = INT_MIN;
        for(const int num : nums) {
            if(num < smallest) {
                secSmallest = smallest;
                smallest = num;
            } else if (num < secSmallest) {
                secSmallest = num;
            }

            if(num > biggest) {
                thirdBiggest = secBiggest;
                secBiggest = biggest;
                biggest = num;
            } else if (num > secBiggest) {
                thirdBiggest = secBiggest;
                secBiggest = num;
            } else if (num > thirdBiggest) {
                thirdBiggest = num;
            }
        }

        return max({
            (smallest * secSmallest * biggest),
            (biggest * secBiggest * thirdBiggest),
        });
    }
};