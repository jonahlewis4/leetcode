class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.size() % 2 == 1) {
            char middle = num[num.size() / 2];
            if(middle != '0' && middle != '1' && middle != '8'){
                return false;
            }
        }

        for(int i = 0; i < num.size() / 2; i++) {
            int rI = num.size() - i - 1;
            char r = num[rI];
            char l = num[i];

            if(r == '6' && l == '9'){
                continue;
            }

            if(l == '6' && r == '9'){
                continue;
            }


            if(l == '1' && r == '1') {
                continue;
            }

            if(l == '8' && r == '8') {
                continue;
            }

            if(l == '0' && r == '0'){
                continue;
            }

            return false;
        }

        return true;
    }
};