class Solution {
private:
    static constexpr int mod = 1e9 + 7;
public:
    int possibleStringCount(string word, int k) {
        if(word.size() < k) {
            return 0;
        }
        if(word.size() == k) {
            return 1;
        }

        vector<int> consec = {1};
        for(int i = 1; i < word.size(); i++) {
            if(word[i] == word[i - 1]) {
                consec.back()++;
            } else {
                consec.push_back(1);
            }
        }
        
        

        long long totalStrings = 1;
        bool noMods = true;
        for(const auto & num : consec) {
            totalStrings *= num;
            if(totalStrings >= mod){
                totalStrings = totalStrings % mod;
                noMods = false;
            }
        }

        if(totalStrings == 1 && noMods) {
            return 1;
        }

        if(k <= consec.size()) {
            return totalStrings;
        }

        int maxT=k-consec.size()-1;
        long long dp[2][2000]={0}, prefix[2001]={0};
        dp[0][0]=1;

        for (int j=0; j<consec.size(); j++) {
            const int s=consec[j];
            for (int i=0; i<=maxT; i++){
                prefix[i+1]=(prefix[i]+dp[j&1][i])%mod;// 1-indexed prefix sum
                int L=max(0, i-(s-1)), R=i;
                dp[(j+1)&1][i]=(prefix[R+1]-prefix[L]+mod)%mod;
            }
        }

        long long lessK=0;
        for (long long x : dp[consec.size()&1])
            lessK=(lessK+x)%mod;

        return (totalStrings-lessK+mod) % mod;

    }
};