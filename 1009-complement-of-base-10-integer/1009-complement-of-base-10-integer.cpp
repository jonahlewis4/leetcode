class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }
        int leading0s = __builtin_clz(n);

        int comp = ~n;
        //cout<<comp<<endl;
        int shiftL = comp << leading0s;
        //cout<<shiftL<<endl;
        int shiftR = shiftL >> leading0s;
        //cout<<shiftR<<endl;

        return shiftR;

    }
};