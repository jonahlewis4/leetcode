class Solution {
private:
    unordered_map<char, vector<char>> letters = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},

    };
public:
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        vector<string> res;
        string cur = "";
        calc(digits, res, cur, 0);
        return res;
    }
    void calc(const string& digits, vector<string>& res, string& cur, const int i){
        if(i >= digits.size()){
            res.push_back(cur);
            return;
        }
        for(const char c : letters[digits[i]]){
            cur.push_back(c);
            calc(digits, res, cur, i + 1);
            cur.pop_back();
        }
    }
};