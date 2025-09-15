class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broke;
        for(const char c : brokenLetters) {
            broke.insert(c);
        }
        int total = 0;
        bool broken = false;
        text += " ";
        for(const char c : text){
            switch (c) {
                case ' ':{
                    if(!broken) {
                        total++;
                    }
                    broken = false;

                    break;
                }
                default: {
                    if(broke.find(c) != broke.end()) {
                        broken = true;
                    }
                }
            }
        }

        return total;
    }
};