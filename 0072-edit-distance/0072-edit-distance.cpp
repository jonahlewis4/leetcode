class Solution {
public:
    int minDistance(string word1, string word2) {
        

        if(word1.size() < word2.size()){
            swap(word1, word2); 
        }

        if(word2.size() == 0){
            return word1.size();
        }

        vector<int> dp(word2.size());
        for(int c = 0; c < dp.size(); c++){
            dp[c] = word2.size() - c;
        }

        for(int r = word1.size() - 1; r >= 0; r--){
            int bottomRight = word1.size() - r - 1;
            int right = bottomRight + 1;
            for(int c = word2.size() - 1; c >= 0; c--){
                int below = dp[c];
                if(word1[r] == word2[c]){
                    dp[c] = bottomRight;
                } else {
                    int replace = bottomRight;
                    int _delete = below;
                    int add = right;
                    
                    int best = min({replace, _delete, add});
                    dp[c] = best + 1;
                }


                bottomRight = below;
                right = dp[c];
            }
        }

        return dp[0];
    }
    
    
};
    
