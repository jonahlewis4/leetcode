class Solution {
public:
    int maxScore(string s) {
        //score = 0l + 1T - 1l
        //maximize 0l - 1l

        int maxDif = 0;
        int zCount = 0;
        int oCount = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0' && i < s.size() - 1){
                zCount++;
            } else if(s[i] == '1' && i >= 1){
                oCount++;
            }
            maxDif = max(maxDif, zCount - oCount);
        }

        
        return maxDif + oCount;

    }
};