class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        if(s.size() != t.size()){
            if(abs((int)s.size() - (int)t.size()) != 1){
                return false;
            }
        }

        int sI = 0;
        int tI = 0;

        bool freebieUsed = false;
        while(sI < s.size() && tI < t.size()) {
            char sC = s[sI];
            char tC = t[tI];

            if(sC != tC) {
                if(freebieUsed) {
                    return false;
                }
                freebieUsed = true;
                if(s.size() < t.size()) {
                    tI++;
                    continue;
                } else if (s.size() > t.size()) {
                    sI++;
                    continue;
                } 
            } 
            sI++;
            tI++;
        }

        if((sI < s.size() || tI < t.size())){
            return !freebieUsed;
        }

        return freebieUsed;
    }
};