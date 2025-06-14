class Solution {
private:
    string s;
    int k;

    enum Parity {
        EVEN_EVEN,
        EVEN_ODD,
        ODD_EVEN,
        ODD_ODD
    };

    Parity compliment(Parity p) const {
        if(p == EVEN_EVEN) {
            return ODD_EVEN;
        } else if (p == EVEN_ODD) {
            return ODD_ODD;
        } else if (p == ODD_EVEN) {
            return EVEN_EVEN;
        }
        return EVEN_ODD;
    }

    vector<int> prefixArray(char search) const {
        vector<int> res(s.size() + 1, 0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == search) {
                res[i + 1] = res[i] + 1;
            } else {
                res[i + 1] = res[i];
            }
        }
        return res;
    }

    Parity countsToParity(int aCount, int bCount) const {
        if(aCount % 2 == 0 && bCount % 2 == 0){
            return EVEN_EVEN;
        } else if (aCount % 2 == 0  && bCount % 2 == 1) {
            return EVEN_ODD;
        } else if (aCount % 2 == 1 && bCount % 2 == 0){
            return ODD_EVEN;
        }
        return ODD_ODD;
    }

    int bestForAB(char a, char b) const {
        vector<int> aPrefix = prefixArray(a);
        vector<int> bPrefix = prefixArray(b);
        
        vector<int> idxSmallestOfParity(4, INT_MIN);
        idxSmallestOfParity[EVEN_EVEN] = -1;

        int best = INT_MIN;
        for(int r = k - 1; r < s.size(); r++){
            int aCount = aPrefix[r + 1];
            int bCount = bPrefix[r + 1];
            Parity parity = countsToParity(aCount, bCount);
            int comp = compliment(parity);
            {
                int oldIndex = idxSmallestOfParity[comp];
                if(oldIndex != INT_MIN) {
                    //ensure b count has changed (i.e, not 0)
                    int oldACount = aPrefix[oldIndex + 1];
                    int oldBCount = bPrefix[oldIndex + 1];

                    if(bCount - oldBCount != 0){
                        int numAInWindow = aCount - oldACount;
                        int numBInWindow = bCount - oldBCount;
                        int diff = numAInWindow - numBInWindow;
                        best = max(best, diff);
                    }
                }
            }

            //update indices of idxSmallestOfParity.
            {
                

                //look at result after moving left over 1.
                //left is r - k + 1
                int left = r - k + 1;

                int leftACount = aPrefix[left + 1];
                int leftBCount = bPrefix[left + 1];

                int leftParity = countsToParity(leftACount, leftBCount);


                int prevSmallestIndex = idxSmallestOfParity[leftParity];
                if(prevSmallestIndex == INT_MIN) {
                    idxSmallestOfParity[leftParity] = left;
                } else {
                    int prevSmallestACount = aPrefix[prevSmallestIndex + 1];
                    int prevSmallestBCount = bPrefix[prevSmallestIndex + 1];
                    int prevSmallestDiff = prevSmallestACount - prevSmallestBCount;

                    int leftDiff = leftACount - leftBCount;
                    if(leftDiff < prevSmallestDiff) {
                        idxSmallestOfParity[leftParity] = left;
                    }
                }
                

            }
            
        }

        return best;
        
    }
public:
    int maxDifference(const string& s, int k) {
        int best = INT_MIN;
        this->s = s;
        this->k = k;
        for(char a = '0'; a <= '4'; a++){
            for(char b = '0'; b <= '4'; b++){
                if(a == b){
                    continue;
                }
                int localBest = bestForAB(a,b);
                best = max(best, localBest);   
            }
        }
        return best;
    }
};