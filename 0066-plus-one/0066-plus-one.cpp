class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> res(digits.size());
        for(int i = digits.size() - 1; i >= 0; i--){
            int newDigit = digits[i] + carry;
            if(newDigit >= 10) {
                newDigit = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            digits[i] = newDigit;

        }
        if(carry > 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};