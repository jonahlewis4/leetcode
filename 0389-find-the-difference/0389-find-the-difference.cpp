class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> sCount;
        unordered_map<char, int> tCount;
        for(const char c : s){
            sCount[c]++;
        }
        for(const char c : t){
            tCount[c]++;
            if(tCount[c] > sCount[c]){
                return c;
            }
        }
        return '!';
    }
};