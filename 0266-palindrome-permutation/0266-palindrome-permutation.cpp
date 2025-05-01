class Solution {
public:
    bool canPermutePalindrome(string s) {
        array<int, 26> letters;
        for(const auto & c : s){
            letters[c - 'a']++;
        }

        bool parachute = true;
        for(const auto & count : letters){
            if(count % 2 == 1){
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