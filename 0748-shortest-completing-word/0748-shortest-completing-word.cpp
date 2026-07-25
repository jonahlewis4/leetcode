class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> plate;
        for(const char c : licensePlate) {
            if(isalpha(c)) {
                plate[tolower(c)]++;
            }
        }

        string res = "";

        for(const string& word : words) {
            unordered_map<char, int> map = plate;
            for(const char c : word) {
                if(isalpha(c)) {
                    char lower = tolower(c);

                    if(!map.contains(lower)) {
                        continue;
                    }

                    map[lower]--;


                    if(map[lower] == 0) {
                        map.erase(lower);
                        if(map.empty()) {
                            if(res == "" || word.size() < res.size()) {
                                res = word;
                            }

                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
};