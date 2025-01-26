class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int onesOnTheLeft = 0;
        int zeroesOnTheRight = 0;
        for(const char c : s){
            if(c == '0'){
                zeroesOnTheRight++;
            }
        }
        int minFlip = s.size();
        for(int i = 0; i < s.size(); i++){
            int flips = onesOnTheLeft + zeroesOnTheRight;
            minFlip = min(minFlip, flips);
            if(s[i] == '0'){
                zeroesOnTheRight--;
            }
            if(s[i] == '1'){
                onesOnTheLeft++;
            }
        }
        int final = onesOnTheLeft + zeroesOnTheRight;
        return min(final, minFlip);
    }
};