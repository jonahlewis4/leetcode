class Solution {
public:
    int nextGreaterElement(int n) {
        multiset<int> digits;
        int nCopy = n;
        unsigned int res = 0;
        int prev = 0;
        int i = 0;
        int barrierI = -1;
        unsigned int tenPow = 1;
        int barDigit = 0;
        while(nCopy > 0) {
            int curDigit = nCopy % 10;
            if(i > barrierI && barrierI > 0) {
                res += tenPow * curDigit;
            } else {
                if(curDigit < prev){
                    barrierI = i;
                    barDigit = curDigit;
                }

                digits.insert(curDigit);
            }
            
            nCopy /=10;
            prev = curDigit;
            i++;
            tenPow *= 10;
        }
        if(barrierI == -1) {
            return -1;
        }
        
        multiset<int>::iterator itr = digits.upper_bound(barDigit);
        if(itr == digits.end()) {
            return -1;
        }

        int replace = *itr;
        digits.erase(itr);
        long long additive = (long long)pow(10, barrierI) * replace;
        if(additive > INT_MAX) {
            return -1;
        }
        res += additive;

        tenPow = 1;
        for(multiset<int>::reverse_iterator itr = digits.rbegin(); itr != digits.rend();) {
            int digit = *itr;
            res += tenPow * digit;
            tenPow *= 10;

            multiset<int>::iterator forward_it = next(itr).base();
            itr = make_reverse_iterator(digits.erase(forward_it));
        }
        if(res > INT_MAX) {
            return -1;
        }
        return res;
    }
};