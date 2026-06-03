class Solution {
public:
    string getHint(string secret, string guess) {
        std::array<int, 10> cowCandidates{};
        int bulls = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] != guess[i]) {
                int idx = secret[i] - '0';
                cowCandidates[idx]++;
            } else {
                bulls++;
            }
        }
        int cows = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] != guess[i]) {
                int idx = guess[i] - '0';
                int remaining = cowCandidates[idx];
                if(remaining > 0) {
                    cows++;
                    cowCandidates[idx]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";


    }
};