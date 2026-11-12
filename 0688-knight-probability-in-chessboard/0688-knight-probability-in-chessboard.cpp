class Solution {
    static vector<pair<int, int>> const dirs;
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> prevDp(n, vector<double>(n, 1));
        vector<vector<double>> curDp(n, vector<double>(n, 0));

        for(int kI = 1; kI <= k; kI++){
            for(int r = 0; r < n; r++) {
                for(int c = 0; c < n; c++) {
                    double res = 0;
                    for(const pair<int, int> dir : dirs) {
                        int newRow = r + dir.first;
                        int newCol = c + dir.second;

                        if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) {
                            continue;
                        }
                        
                        res += prevDp[newRow][newCol];
                    }
                    res/=dirs.size();
                    curDp[r][c] = res;
                }
            }
            swap(prevDp, curDp);
        }

        return prevDp[row][column];

    }
};
vector<pair<int, int>> const Solution::dirs = {
    {1,2},
    {2,1},
    {-1, 2},
    {-2, 1},
    {1, -2},
    {2, -1},
    {-1, -2},
    {-2, -1}
};