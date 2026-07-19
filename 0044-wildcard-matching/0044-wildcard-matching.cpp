class Solution {
public:
    bool isMatch(string s, string p) {
        int lastStar = -1;
        int starProgress = -1;

        int sI = 0;
        int pI = 0;
        while(sI < s.size()) {
            if(pI < p.size() && (p[pI] == s[sI] || p[pI] == '?')) {
                sI++;
                pI++;
            } else if (pI < p.size() && p[pI] == '*'){
                lastStar = pI;
                starProgress = sI; 
                pI++;
            } else if(lastStar != -1) {
                starProgress++;
                sI = starProgress;
                pI = lastStar + 1;
            } else {
                return false;
            }
        }
        while(pI < p.size() && p[pI] == '*'){
            pI++;
        }

        return pI == p.size();
    }

};