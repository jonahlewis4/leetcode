class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.back() == 1) {
            return false;
        }

        for(int i = 0; true;) {
            if(i >= bits.size()){
                return false;
            }

            if(i == bits.size() - 1) {
                return true;
            }

            switch(bits[i]){
                case (0): {
                    i++;
                    break;
                }
                case (1): {
                    i+=2;
                    break;
                }
            }
        }
    }
};