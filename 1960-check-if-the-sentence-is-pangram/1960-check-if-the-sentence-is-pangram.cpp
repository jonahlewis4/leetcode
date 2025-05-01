class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> letters;
        for(const auto & c : sentence){
            letters.insert(c);
        }
        return letters.size() == 26;
    }
};