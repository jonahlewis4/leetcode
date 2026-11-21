class Solution {
    vector<pair<int, int>> dirs = {
        {0,1},
        {0,-1},
        {1, 1},
        {1, -1},
        {1, 0},
        {-1, 0},
        {-1, 1},
        {-1, -1}
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.front().front() == 1) {
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 2;
        for(int j = 1; !q.empty(); j++) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                pair<int, int> coords = q.front();
                q.pop();
                int r = coords.first;
                int c = coords.second;
                if(r == grid.size() - 1 && c == grid.front().size() - 1) {
                    return j;
                }

                for(const pair<int, int> dir : dirs) {
                    int rChange = dir.first;
                    int cChange = dir.second;
                    int newR = r + rChange;
                    int newC = c + cChange;

                    if(newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid.front().size()) {
                        continue;
                    }

                    if(grid[newR][newC] == 2){
                        continue;
                    }
                    if(grid[newR][newC] == 1){
                        continue;
                    }
                    

                    grid[newR][newC] = 2;
                    q.push({newR, newC});
                }
            }
        }
        return -1;
    }
};