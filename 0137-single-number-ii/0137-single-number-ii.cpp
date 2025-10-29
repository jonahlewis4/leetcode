class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count = 0;

        for(int digNum = 0; digNum < 32; digNum++){
            int thisDigit = 0;
            for(const auto & num : nums) {
                int numDigit = (num & (1 << digNum)) >> digNum;
                thisDigit += numDigit;
            }

            count |= (thisDigit % 3) << digNum;
        }

        return count;
    }
};