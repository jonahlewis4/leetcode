class Solution {

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        class Info{
            vector<vector<bool>> grid;

            vector<vector<int>> lastL;
            vector<vector<int>> lastU;
            vector<vector<int>> nextR;
            vector<vector<int>> nextB;
        public:
            Info(int m, int n, const vector<vector<int>>& coords){
                grid.resize(m, vector<bool>(n, false));
                lastL.resize(m, vector<int>(n, -1));
                lastU.resize(m, vector<int>(n, -1));
                nextB.resize(m, vector<int>(n, m));
                nextR.resize(m, vector<int>(n, n));

                const auto & l = lastL;
                const auto & u = lastU;
                const auto & r = nextR;
                const auto & b = nextB;

                for(const vector<int>& coord : coords) {
                    int r = coord[0];
                    int c = coord[1];

                    grid[r][c] = true;
                }

                for(int r = 0; r < m; r++) {
                    int last = -1;
                    for(int c = 0; c < n; c++){
                        lastL[r][c] = last;
                        if(grid[r][c]){
                            last = c;
                        }
                    }
                }

                for(int c = 0; c < n; c++) {
                    int last = -1;
                    for(int r = 0; r < m; r++) {
                        lastU[r][c] = last;
                        if(grid[r][c]){
                            last = r;
                        }
                    }
                }

                for(int r = 0; r < m; r++) {
                    int last = n;
                    for(int c = n - 1; c >= 0; c--){
                        nextR[r][c] = last;
                        if(grid[r][c]){
                            last = c;
                        }
                    }
                }

                for(int c = 0; c < n; c++) {
                    int last = m;
                    for(int r = m - 1; r >= 0; r--) {
                        nextB[r][c] = last;
                        if(grid[r][c]){
                            last = r;
                        }
                    }
                }
            }

            int lOf(int r, int c) const {
                return lastL[r][c];
            }
            int rOf(int r, int c) const {
                return nextR[r][c];
            }
            int uOf(int r, int c) const {
                return lastU[r][c];
            }
            int bOf(int r, int c) const {
                return nextB[r][c];
            }

            bool occupied(int r, int c) const {
                return grid[r][c];
            }
        };

        Info guardInfo(m, n, guards);
        Info wallInfo(m, n, walls);

        int total = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(wallInfo.occupied(r, c) || guardInfo.occupied(r, c)){
                    total++;
                    continue;
                }


                int lWall = wallInfo.lOf(r, c);
                int lGuard = guardInfo.lOf(r, c);

                if(lGuard > lWall) {
                    total++;
                    continue;
                }

                int rWall = wallInfo.rOf(r, c);
                int rGuard = guardInfo.rOf(r, c);

                if(rGuard < rWall) {
                    total++;
                    continue;
                }

                int uWall = wallInfo.uOf(r, c);
                int uGuard = guardInfo.uOf(r, c);
                
                if(uGuard > uWall) {
                    total++;
                    continue;
                }

                int bWall = wallInfo.bOf(r, c);
                int bGuard = guardInfo.bOf(r, c);

                if(bGuard < bWall) {
                    total++;
                    continue;
                }
            }
        }

        int squareCount = m * n;
        return squareCount - total;
    }
};