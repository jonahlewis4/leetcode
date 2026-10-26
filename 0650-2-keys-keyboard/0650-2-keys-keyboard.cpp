class Solution {
public:
    int minSteps(int n) {
        int onScreen = 1;
        int clipBoard = 0;

        int total = 0;
        while(onScreen != n){
            int remaining = n - onScreen;
            if(n % onScreen == 0) {
                total+=2;
                clipBoard = onScreen;
                onScreen *= 2;
            } else {
                total++;
                onScreen += clipBoard;
            }
        }

        return total;
    }
};