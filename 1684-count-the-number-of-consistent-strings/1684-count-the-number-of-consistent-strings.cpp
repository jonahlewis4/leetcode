class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        unordered_set<char> in;
        for(const char c : allowed) {
            in.insert(c);
        }

        for(const string& word : words) {
            bool works = true;
            for(const char c : word) {
                if(!in.contains(c)) {
                    works = false;
                    break;
                }
            }

            if(works) {
                count++;
            }
        }

        return count;
    }
};