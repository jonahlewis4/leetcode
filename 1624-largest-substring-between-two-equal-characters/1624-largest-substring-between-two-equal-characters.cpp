class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> first;
        unordered_map<char, int> last;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            last[c] = i;
        }
        for(int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            first[c] = i;
        }

        int largestDiff = -1;
        for(const auto& [c, start] : first) {
            if(!last.contains(c)) {
                continue;
            }

            int lastOccurance = last[c];
            int numInBetween = lastOccurance - start - 1;
            largestDiff = max(largestDiff, numInBetween);
        }

        return largestDiff;

    }
};