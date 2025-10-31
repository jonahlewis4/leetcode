class Solution {
public:
    int bulbSwitch(int n) {
        
        for(int i = 1; true; i++){
            if(i * i > n){
                return i - 1;
            }
        }


    }
};