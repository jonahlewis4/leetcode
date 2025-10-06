class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const vector<int>& s = fruits;
        int l = 0;
        int r = 0;

        unordered_map<int, int> count;
        for(const int c : s) {
            if(count.size() == 2){
                break;
            }
            count[c]++;
            r++;
        }

        int best = 0;
        while(r < s.size()) {
            int newC = s[r];
            if(count.size() < 2 || count.contains(newC)){
                count[newC]++;
                r++;
            } else {
                best = max(best, r - l);
                while(count.size() == 2) {
                    int lChar = s[l];
                    count[lChar]--;
                    l++;
                    if(count[lChar] == 0){
                        count.erase(lChar);
                    }
                }
            }
        }

        best = max(best, r - l);
        return best;
    }
};