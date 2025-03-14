//65  = 0100 0001
//15 = 0000 1111
// x = 0100 0111

class Solution {
private:
static int leftMostBit;  
public:
    int minimizeXor(unsigned int num1, unsigned int num2) {
        //get number of bits in num2.
        unsigned int ones = num1s(num2);
        unsigned int res = 0;
        unsigned int num1copy = num1;
        unsigned int digit = leftMostBit;
        while(num1copy > 0 && ones > 0){
            //cout<<bitset<32>(num1copy)<<endl;
            if((num1copy & leftMostBit) == leftMostBit){
                res ^= digit;
                ones--;
            }
            digit >>= 1;
            num1copy <<= 1;
        }

        digit = 1;
        while(ones > 0){
            if((num1 & 1) == 0){
                res ^= digit;
                ones--;
            }
            digit <<= 1;
            num1 >>= 1;
        }
        return res;

    }
    unsigned int num1s(unsigned int num) const {
        unsigned int count = 0;
        while(num > 0){
            if((num & 1) == 1){
                count++;
            }
            num >>= 1; 
        }
        return count;
    }
};
int Solution::leftMostBit = 0b10000000000000000000000000000000;