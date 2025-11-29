class Solution {
    unordered_map<char, int> countOf(const string& s) {
        unordered_map<char, int> res;
        for(const char c : s) {
            res[c]++;
        }

        return res;
    }

    void generate(string& cur, vector<string>& res, 
        unordered_map<char, int>& counts, int i
    ){
        int half = cur.size() / 2;
        if(cur.size() % 2 == 0 && i == half){
            res.push_back(cur);
            return;
        }
        if(cur.size() % 2 == 1 && i == half + 1) {
            res.push_back(cur);
            return;
        }

        bool centerIndex = cur.size() % 2 == 1 && i == half;

        for( auto& [c, count] : counts) {
            if(count == 0) {
                continue;
            }
            cur[i] = c;
            count--;
            if(!centerIndex && count < 1) {
                count++;
                continue;
            }

            if(!centerIndex) {
                int back = cur.size() - 1 - i;
                cur[back] = c;
                count--;
            }

            generate(cur, res, counts, i + 1);
            count++;

            if(!centerIndex) {
                count++;
            }
        }

    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> counts = countOf(s);
        string cur(s.size(), '.');
        vector<string> res;

        generate(cur, res, counts, 0);
        return res;
    }
};