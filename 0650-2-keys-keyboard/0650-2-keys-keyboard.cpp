class Solution {
    int calculate(int onScreen, int totalNeeded, int clipBoard){
        if(onScreen == totalNeeded) {
            return 0;
        }

        //copy
        int remaining = totalNeeded - onScreen;
        if(totalNeeded % onScreen == 0){
            return 2 + calculate(onScreen * 2, totalNeeded, onScreen);
        }

        return 1 + calculate(onScreen + clipBoard, totalNeeded, clipBoard);
    }
public:
    int minSteps(int n) {
        return calculate(1, n, 0);
    }
};