class Solution {
public:
    int numDecodings(string s) {

        int twoAgo = 1;
        int oneAgo = s[s.size() - 1] != '0';

        for(int i = s.size() - 2; i >= 0; i--){
            char c = s[i];
            int cur;
            if(c > '2'){
                cur = oneAgo;
            } else if (c == '0'){
                cur = 0;
            } else if (c == '1'){
                cur = oneAgo + twoAgo;
            } else if (c == '2' && s[i + 1] <= '6'){
                cur = oneAgo + twoAgo;
            } else {
                cur = oneAgo;
            }
            
            twoAgo = oneAgo;
            oneAgo = cur;
        }


        return oneAgo;
    }
};