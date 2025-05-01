class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::array<bool, 26> letters;
        for(const auto & c : sentence){
            letters[c - 'a'] = true;
        }
        for(const auto & found : letters){
            if(!found){
                return false;
            }
        }
        return true;
    }
};