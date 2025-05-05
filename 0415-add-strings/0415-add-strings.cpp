class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int carry = 0;
        for(int i = 0; i < max(num1.size(), num2.size()); i++){
            int localSum = 0;
            if(i < num1.size()){
                localSum += num1[i] - '0';
            }

            if(i < num2.size()){
                localSum += num2[i] - '0';
            }

            localSum += carry;

            carry = localSum / 10;
            localSum = localSum % 10;

            res.push_back(char(localSum) + '0');
        }        

        if(carry){
            res += '1';
        }

        reverse(res.begin(), res.end());

        return res;

    }
};