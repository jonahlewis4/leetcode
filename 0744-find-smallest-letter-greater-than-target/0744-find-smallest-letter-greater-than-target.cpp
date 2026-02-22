class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char nextGreatest = '.';
        for(const char c : letters) {
            if(c > target){
                if(nextGreatest == '.' || c < nextGreatest) {
                    nextGreatest = c;
                }
            }
        }

        nextGreatest = nextGreatest == '.' ? letters.front() : nextGreatest;
        return nextGreatest;
    }
};