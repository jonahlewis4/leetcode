class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans = "";

        if(numFriends == 1){
            return word;
        }

        int bestLen = word.size() - numFriends + 1;

        for(int i = 0; i < word.size(); i++){
            int remainingLength = min(bestLen, int(word.size()) - i);
            string sub = word.substr(i, remainingLength);
            ans = max(sub, ans);
        }
        return ans;
    }
};