class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32, 0);
        for(const int num : nums) {
            uint num2 = num;
            int mPlier = 0;
            while(num2 > 0){
                int digit = num2 % 2;
                if(digit){
                    count[mPlier]++;
                    count[mPlier] %= 3;
                }
                mPlier++;
                num2 /= 2;
            }
        }

        int res = 0;
        uint mPlier = 1;
        for(int i = 0; i < count.size(); i++){
            int amt = count[i];
            res += mPlier * amt;
            mPlier *= 2;
        }

        return res;


    }
};