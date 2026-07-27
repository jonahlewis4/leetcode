class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = INT_MIN;
        int secondBiggest = INT_MIN;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(const int num : nums) {
            if(num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else if (num > secondBiggest) {
                secondBiggest = num;
            }

            if(num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else if (num < secondSmallest) {
                secondSmallest = num;
            }
        }

        return max(
            (biggest - 1) * (secondBiggest - 1),
            (smallest - 1) * (secondSmallest - 1)

        );
    }
};