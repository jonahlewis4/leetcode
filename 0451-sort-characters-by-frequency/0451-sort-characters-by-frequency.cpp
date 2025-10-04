class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        for(const char c : s) {
            count[c]++;
        }

        vector<vector<char>> freq(n + 1);
        
        for(const auto & [c, count] : count) {
            freq[count].push_back(c);
        }

        int i = 0;
        for(int j = n; j >= 0; j--) {
            for(const char c : freq[j]){
                for(int k = 0; k < j; k++) {
                    s[i] = c;
                    i++;
                }
            }
        }
        


      
        return s;
    }
};