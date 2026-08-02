class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        
        int carry = 0;
        for(int i = 0; k > 0 || i < num.size(); i++, k/=10) {
            int sum = 0;
            sum += carry;
            sum += k % 10;
            if(i < num.size()) {
                sum += num[i];
            }

            if(i >= num.size()) {
                num.push_back(0);
            }
            
            num[i] = sum % 10;

            carry = sum / 10;
        }
        

        if(carry) {
            num.push_back(1);
        }

        reverse(num.begin(), num.end());
        return num;
    }
};