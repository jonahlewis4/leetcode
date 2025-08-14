class Solution {
public:
    string largestGoodInteger(string num) {
        char twoAgo = '\0';
        char oneAgo = '\0';
        string best = "";
        for(const auto & c : num) {
            if(twoAgo == oneAgo && oneAgo == c) {
                string comb = {c, c, c};
                if(best == "" || comb > best) {
                    best = comb;
                }
            }
            twoAgo = oneAgo;
            oneAgo = c;
        }
        return best;
    }
};