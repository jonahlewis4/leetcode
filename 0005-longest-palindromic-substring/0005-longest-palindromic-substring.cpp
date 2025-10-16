class Solution {
public:
    string longestPalindrome(const string& s) {
        string longest = "";

        int bestR = 0;
        int bestL = 0;
        const auto  find = [&s, &bestR, &bestL](int l, int r){
            while(l >= 0 && r < s.size()){
                if(s[l] != s[r]){
                    break;
                }
                l--;
                r++;
            }

            int palL = l + 1;
            int palR = r - 1;

            if(palR - palL > bestR - bestL){
                bestR = palR;
                bestL = palL;
            }
        };

        for(int i = 0; i < s.size(); i++){
            find(i, i);
        }

        for(int i = 1; i < s.size(); i++){
            find(i - 1, i);
        }

        return s.substr(bestL, bestR - bestL + 1);

    }
};