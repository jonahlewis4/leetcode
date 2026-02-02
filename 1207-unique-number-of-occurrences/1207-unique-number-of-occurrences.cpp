class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> c;
        for(const int i : arr) {
            c[i]++;
        }

        unordered_set<int> s;
        for(const auto & [_, cnt] : c) {
            if(s.contains(cnt)) {
                return false;
            }
            s.insert(cnt);
        }

        return true;
    }
};