class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = INT_MIN;
        int secondBiggest = INT_MIN;

        for(const int num : nums) {
            if(num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else if (num > secondBiggest) {
                secondBiggest = num;
            }

        }

        return (biggest - 1) * (secondBiggest - 1);

    }
};