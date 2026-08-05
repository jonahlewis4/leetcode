class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> count;
        string mostCommon;
        int highestCount = 0;
        unordered_set<string> banSet;
        for(string& s : banned) {
            for(char& c : s) {
                c = tolower(c);
            }
            banSet.insert(s);
        }

        string cur = "";
        const auto handleWord = [&count, &mostCommon, &highestCount, &banSet, &cur]() {
            if(cur.size() > 0 && !banSet.contains(cur)) {
                if(++count[cur] > highestCount){
                    mostCommon = cur;
                    highestCount++;
                }
            }
            cur = "";

        };
        for(const char c : paragraph) {
            if(isalpha(c)) {
                cur += tolower(c);
            } else {
                handleWord();
            }
        }

        handleWord();
        return mostCommon;
    }
};