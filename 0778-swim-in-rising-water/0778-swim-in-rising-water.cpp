class Solution {
    vector<pair<int, int>> dirs {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        int t = 0;
        struct Cell {
            int r;
            int c;
            int t;
        };

        priority_queue<Cell, vector<Cell>, decltype([](const Cell& a, const Cell& b){
            return a.t > b.t;
        })> pq;

        pq.push({
            .r = 0,
            .c = 0,
            .t = grid.front().front(),
        });

        while(!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();

            t = max(cell.t, t);
            if(cell.r == grid.size() - 1 && cell.c == grid.front().size() - 1){
                return t;
            }   

            grid[cell.r][cell.c] = -1;

            for(const auto & [rc, cc] : dirs) {
                int newR = cell.r + rc;
                int newC = cell.c + cc;

                if(newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid.front().size()) {
                    continue;
                }


                //if not visited;
                if(grid[newR][newC] == -1) {
                    continue;
                }


                pq.push({
                    .r = newR,
                    .c = newC,
                    .t = grid[newR][newC]
                });
            }

        }

        return -1;

    }
};