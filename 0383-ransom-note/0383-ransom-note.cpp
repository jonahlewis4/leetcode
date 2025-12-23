class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> avail;
        for(const char c : magazine) {
            avail[c]++;
        }

        for(const char c : ransomNote) {
            if(avail[c] == 0) {
                return false;
            }

            avail[c]--;
        }

        return true;
    }
};