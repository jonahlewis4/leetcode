class Solution {
    static int getRepeated(int n) {
        if(n <= 1) {
            return 0;
        }


        if(n == 2) {
            return 9;
        }
        
        int total = 0;
        for(int i = 1; i <= n - 1; i++) {
            int subTotal = 0;
            for(int j = i + 1; j <= n; j++) {
                //i j 10 10
                //i 9 j 10
                //i 9 8 j
                //9 i j 10
                //9 i 8 j
                //9 8 i j

                //i j 10
                //i 9 j
                //9 i j

                int iCon = 9;
                int jCon = 1;
                int afterJCon = max(1.0, pow(10, (n - j)));
                
                int r = j - 2;
                int beforeICon = 1;
                for(int k = 1; k <= r; k++) {
                    beforeICon *= (9 - k + 1);
                }
                int subSubTotal = iCon * jCon * beforeICon * afterJCon;
                //cout<<i<<" "<<j<<" "<<subSubTotal<<endl;
                subTotal += subSubTotal;
            }
            total += subTotal;
        }
        //cout<<"_____________"<<endl;
        return total;
    
        
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        int repeated = 0;
        for(int i = 1; i <= n; i++) {
            repeated += getRepeated(i);
        }
        return pow(10, n) - repeated;
    }
};