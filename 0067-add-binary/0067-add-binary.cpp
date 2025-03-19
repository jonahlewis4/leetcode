class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        bool carry = false;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0){
            int bVal;
            int aVal;
            if(j < 0){
                bVal = 0;
            } else {
                bVal = b[j] - '0';
            }

            if(i < 0){
                aVal = 0;
            } else {
                aVal = a[i] - '0';
            }

            if((bVal + aVal + carry) % 2 == 0){
                res += '0';
            } else {
                res += '1';
            }
            if(bVal + aVal + carry >= 2){
                carry = true;
            } else {
                carry = false;
            }
            i--;
            j--;
            
        }

        if(carry){
            res += '1';
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};