class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> wealth(accounts.size());
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 0; j < accounts[i].size(); j++) {
                wealth[i] += accounts[i][j];
            }
        }

        return *(max_element(wealth.begin(), wealth.end()));
    }
};