class Solution {
private:
    static bool isSym(int i) {
        vector<int> digits;
        while(i > 0) {
            digits.push_back(i % 10);
            i /= 10;
        }

        if(digits.size() % 2 == 1) {
            return false;
        }

        int lSum = 0;
        int rSum = 0;
        for(int i = 0; i < digits.size()/2; i++){
            lSum += digits[i];
        }
        for(int i = digits.size()/2; i < digits.size(); i++) {
            rSum += digits[i];
        }

        return lSum == rSum;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++) {
            if(isSym(i)) {
                count++;
            }
        }

        return count;
    }
};