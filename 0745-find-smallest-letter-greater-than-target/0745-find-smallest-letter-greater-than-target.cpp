class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters.back() + 1;
        for(const char c : letters) {
            if(c > target){
                res = min(res, c);
            }
        }
        return res == letters.back() + 1 ?  letters.front() : res;
    }
};