class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> count(n * n + 1, false);
        vector<int> res = {-1,-1};
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[r].size(); c++){
                if(count[grid[r][c]]){
                    res[0] = grid[r][c];

                }
                count[grid[r][c]] = true;
            }
        }

        for(int i = 1; i <= n * n; i++){
            if(count[i] == 0){
                res[1] = i;
                return res;
            }
        }

        return {};
    }
};