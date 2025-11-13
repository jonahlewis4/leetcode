class Solution {
    unordered_set<char> topRow = {
        'q',
        'w',
        'e',
        'r',
        't',
        'y',
        'u',
        'i',
        'o',
        'p',
    };

    unordered_set<char> middleRow = {
        'a',
        's',
        'd',
        'f',
        'g',
        'h',
        'j',
        'k',
        'l',
    };

    unordered_set<char> bottomRow = {
        'z',
        'x',
        'c',
        'v',
        'b',
        'n',
        'm',
    };
    bool allIn(const string& s, const unordered_set<char>& set) {
        for(const char c : s) {
            if(!set.contains(tolower(c))){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(const string& word : words) {
            if(allIn(word, topRow)){
                res.push_back(word);
                continue;
            }

            if(allIn(word, middleRow)){
                res.push_back(word);
                continue;
            }

            if(allIn(word, bottomRow)) {
                res.push_back(word);
            }
        }

        return res;
    }
};