class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<int, int> letters;
        for(const auto & c : s){
            letters[c]++;
        }

        bool parachute = true;
        for(const auto & p : letters){
            if(p.second % 2 == 1){
                if(parachute){
                    parachute = false;
                } else {
                    return false;
                }
            }
        }
        return true;

    }
};