class Solution {
public:
    int possibleStringCount(string word) {
        int repeats = 0;
        for(int i = 1; i < word.size(); i++) {
            if(word[i] == word[i - 1]) {
                repeats++;
            }
        }
        return repeats + 1;
    }
};