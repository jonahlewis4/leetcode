class Solution {
    int m;
    int n;
    int MOD = (int)1e9 + 7;
    static vector<pair<int, int>> dirs;
    vector<vector<vector<int>>> cache;
    int go(int r, int c, int movesLeft) {
        bool outbounds = r < 0 || c < 0 || r >= m || c >= n;
        if(outbounds) {
            return 1;
        }

        if(movesLeft == 0) {
            return 0;
        }

        if(cache[r][c][movesLeft-1] >= 0) {
            return cache[r][c][movesLeft-1];
        }
        int total = 0;
        for(const pair<int, int> coord : dirs) {
            int rChange = coord.first;
            int cChange = coord.second;
            int newR = r + rChange;
            int newC = c + cChange;
            int sub = go(newR, newC, movesLeft - 1);
            total = (total + sub % MOD) % MOD;
        }
        cache[r][c][movesLeft-1] = total;
        return total;

    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        cache.resize(m, vector<vector<int>>(n, vector<int>(maxMove, -1)));
        return go(startRow, startColumn, maxMove);
    }
};
vector<pair<int, int>> Solution::dirs = {
        {0,1},{1,0},{-1,0},{0,-1}
};