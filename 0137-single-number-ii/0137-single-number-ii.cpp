class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count = 0;

        for(int digNum = 0; digNum < 32; digNum++){
            uint thisDigit = 0;
            for(const auto & num : nums) {
                uint numDigit = (num >> digNum) & 1;
                thisDigit += numDigit;
            }

            count |= ((thisDigit % 3) << digNum);
        }

        return count;
    }
};