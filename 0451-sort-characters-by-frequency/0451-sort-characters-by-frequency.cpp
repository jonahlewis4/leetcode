class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        for(const char c : s) {
            count[c]++;
        }

        vector<pair<int, char>> charCounts;
        for(const auto & [c, count] : count) {
            charCounts.push_back({count, c});
        }

        sort(charCounts.begin(), charCounts.end());

        int i = 0;
        for(int j = charCounts.size() - 1; j >= 0; j--) {
            for(int k = 0; k < charCounts[j].first; k++) {
                s[i] = charCounts[j].second;
                i++;
            }
        }

        return s;
    }
};