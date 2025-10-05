class Solution {
    vector<pair<int, int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1},
    };
private:
    vector<vector<int>> heights;
    void dfs(vector<vector<bool>>& ocean, bool isPacific){
        vector<vector<bool>> visited(ocean.size(), vector<bool>(ocean.front().size(), false));
        for(int r = 0; r < ocean.size(); r++) {
            if(isPacific) {
                dfs(ocean, r, 0, visited);
            } else {
                dfs(ocean, r, ocean[r].size() - 1, visited);
            }
        }

        for(int c = 0; c < ocean.front().size(); c++) {
            if(isPacific) {
                dfs(ocean, 0, c, visited);
            } else {
                dfs(ocean, ocean.size() - 1, c, visited);
            }
        }
    }
    void dfs(vector<vector<bool>>& ocean, int r, int c, vector<vector<bool>>& visited) {
        ocean[r][c] = true;
        visited[r][c] = true;

        for(const auto & [x, y] : dirs) {
            int newR = r + y;
            int newC = c + x;

            if(newR < 0 || newC < 0 || newR >= ocean.size() || newC >= ocean[newR].size()) {
                continue;
            }

            //dont go to visited ones
            if(visited[newR][newC]) {
                continue;
            }

            //don't go to smaller values
            if(heights[newR][newC] < heights[r][c]) {
                continue;
            }

            dfs(ocean, newR, newC, visited);
        }
    }

    vector<vector<int>> oceanUnion(const vector<vector<bool>>& a, const vector<vector<bool>>& b) {
        vector<vector<int>> res;
        for(int r = 0; r < a.size(); r++) {
            for(int c = 0; c < a.front().size(); c++) {
                if(a[r][c] && b[r][c]){
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights.front().size(), false));
        vector<vector<bool>> atlantic = pacific;

        dfs(pacific, true);
        dfs(atlantic, false);

        return oceanUnion(pacific, atlantic);
    }
};