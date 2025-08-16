class Solution {
    static vector<vector<int>> dirs;
    void setupIndegrees(vector<vector<int>>& ind, const vector<vector<int>>& matrix) {
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[r].size(); c++) {
                dirAct(r, c, matrix, [&ind, &matrix](int r, int c, int newR, int newC){
                    int curVal = matrix[r][c];
                    int neiVal = matrix[newR][newC];
                    if(neiVal < curVal) {
                        ind[r][c]++;
                    }
                });
            }
        }
    }
    template <typename F>
    void dirAct(int r, int c, const vector<vector<int>>& matrix, F onEach){
        for(const auto & dir : dirs) {
            int rChange = dir[0];
            int cChange = dir[1];
            int newR = r + rChange;
            int newC = c + cChange;
            if(newR < 0 || newC < 0 || newR >= matrix.size() || newC >= matrix[newR].size()) {
                continue;
            }
            onEach(r, c, newR, newC);
        }
    }
    queue<pair<int, int>> getStartQueue(const vector<vector<int>>& ind) {
        queue<pair<int, int>> res;
        for(int r = 0; r < ind.size(); r++) {
            for(int c = 0; c < ind[r].size(); c++){
                if(ind[r][c] == 0){
                    res.push({r, c});
                }
            }
        }
        return res;
    }
    int tSort(vector<vector<int>>& ind, const vector<vector<int>>& matrix){
        int longest = 0;
        queue<pair<int, int>> q = getStartQueue(ind);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                pair<int, int> rC = q.front();
                q.pop();
                int r = rC.first;
                int c = rC.second;
                dirAct(r, c, matrix, [&matrix, &ind, &q](int oldR, int oldC, int newR, int newC) {
                    int oldVal = matrix[oldR][oldC];
                    int newVal = matrix[newR][newC];
                    if(newVal > oldVal) {
                        ind[newR][newC]--;
                        if(ind[newR][newC] == 0) {
                            q.push({newR, newC});
                        }
                    }
                });
            }
            longest++;
        }
        return longest;
    }
public:
    int longestIncreasingPath(const vector<vector<int>>& matrix) {
        vector<vector<int>> indegrees(matrix.size(), vector<int>(matrix[0].size(), 0));
        setupIndegrees(indegrees, matrix);  
        return tSort(indegrees, matrix);
    }

};
vector<vector<int>> Solution::dirs = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}
};