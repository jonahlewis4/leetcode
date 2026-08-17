class Solution {
public:
    string originalDigits(string s) {
        string res;
        unordered_map<char, int> map;
        for(const char c : s) {
            map[c]++;
        }

        const static char keys[10] = {'z', 'g', 'h', 'w', 'x', 'u', 'f', 'v', 'i', 'o'};
        const static string words[10] = {"zero", "eight", "three", "two", "six", "four", "five", "seven", "nine", "one"};
        const static int digit[10] = {0,8,3,2,6,4,5,7,9,1};
        for(int i = 0; i < 10; i++) {
            while(map[keys[i]] > 0) {
                for(const char l : words[i]) {
                    map[l]--;
                }
                res += digit[i] + '0';
            }
        }

        sort(res.begin(), res.end());
        return res;    
    }
};