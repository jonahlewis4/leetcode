class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> mpp = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."},
        {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
        {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."},
        {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
        {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
        {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
        {'y', "-.--"}, {'z', "--.."}};

        unordered_set<string> transformations;
        for(const auto & word : words) {
            string transformation = "";
            for(const auto & c : word) {
                transformation += mpp[c];
            }
            transformations.insert(transformation);
        }
        return transformations.size();
    }
};