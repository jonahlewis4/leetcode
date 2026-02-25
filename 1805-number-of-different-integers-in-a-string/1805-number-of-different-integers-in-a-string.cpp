class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> set;
        string current_number;
        bool primed = false;
        for(const char c : word) {
            if(isdigit(c)) {
                if(current_number.size() > 0 || c != '0'){
                    current_number += c;
                }
                primed = true;
            } else if(primed) {
                set.insert(current_number);
                current_number = "";
                primed = false;
            }
        }
        if(primed) set.insert(current_number);

        return set.size();
    }
};