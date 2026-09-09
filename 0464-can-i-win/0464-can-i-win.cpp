class Solution {
    int topNumber;
    int total;
    
    //a call to r means: can player 1 win if mask looks like this on their turn.
    unordered_map<int, int> map;
    bool r(int mask) {
        if(map.contains(mask)) {
            return map[mask];
        }
        int sumAlreadyChosen = 0;

        for(int i = 0; i < topNumber; i++) {
            if((mask & (1<<i))) {
                int thisNum = i + 1;
                sumAlreadyChosen += thisNum;
            }
        }

        int localTotal = total - sumAlreadyChosen;

        //if there's a number >= localTotal, return true;
        for(int i = topNumber - 1; i >= 0; i--) {
            if((mask & (1<<i)) == 0) {
                int thisNum = i + 1;
                if(thisNum >= localTotal) {
                    map[mask] = true;
                    return true;
                }
            }
        }

        //now check that if there is a choice where it is impossible for player 2 guarantee victory
        for(int i = 0; i < topNumber; i++) {
            if((mask & (1<<i)) == 0) {
                if(!r(mask | (1<<i))){
                    map[mask] = true;
                    return true;
                }                
            }
        }

        //if no path exists, player 2 could win somehow
        map[mask] = false;
        return false;
    }   
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(sum < desiredTotal) {
            return false;
        }
        topNumber = maxChoosableInteger;
        total = desiredTotal; 
        return r(0);
    }
};