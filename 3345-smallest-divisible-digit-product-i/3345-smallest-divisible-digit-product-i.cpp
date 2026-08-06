class Solution {
public:
    int smallestNumber(int n, int t) {
        int product = 1;
        int rightDigit = n % 10;
        int secondDigit = n >= 10 ? n  % 100 / 10 : 1;
        int n2 = n;
        while(n2 > 0) {
            product *= n2 % 10;
            n2/=10;
        }
        
        for(int i = n; i < n + 11; i++){
            int newRightDigit = i % 10;
            int newSecondDigit = (i >= 10) ? i % 100 / 10 : 1;
            if(newRightDigit == 0 || newSecondDigit == 0) {
                return i;
            }
            int lProduct = product / rightDigit * newRightDigit * newSecondDigit / secondDigit ;
            cout<<rightDigit<<endl;
            cout<<newRightDigit<<endl;
            cout<<secondDigit<<endl;
            cout<<newSecondDigit<<endl;
            cout<<i<<endl;
            cout<<lProduct<<endl;
            cout<<endl;
            if(lProduct % t == 0) {
                return i;
            }
        }

        return -1;
    }
};