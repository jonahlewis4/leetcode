class Solution {
public:
    int maxDistance(string _s, int k) {
        int best = 0;
        int n = 0;
        int s = 0;
        int w = 0;
        int e = 0;
        for(int i = 0; i < _s.size(); i++){
            switch(_s[i]){
                case 'N':
                    n++;
                    break;
                case 'S':
                    s++;
                    break;
                case 'W':
                    w++;
                    break;
                case 'E':
                    e++;
                    break;
            }

            
            int bestNS = max(n,s);
            int bestWE = max(w,e);
            int worstNS = min(n,s);
            int worstWE = min(w,e);
            int changeable = worstNS + worstWE;
            changeable = min(changeable, k);
            best = max(best, bestNS + bestWE + changeable * 2 - worstNS - worstWE);
        }
        return best;
    }
};