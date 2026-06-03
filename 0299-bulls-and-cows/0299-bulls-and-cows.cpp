class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_multiset<char> cowCandidates;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] != guess[i]) {
                cowCandidates.insert(secret[i]);
            }
        }
        int bulls = secret.size() - cowCandidates.size();
        int cows = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] != guess[i]) {
                auto itr = cowCandidates.find(guess[i]);
                if(itr != cowCandidates.end()) {
                    cowCandidates.erase(itr);
                    cows++;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";


    }
};