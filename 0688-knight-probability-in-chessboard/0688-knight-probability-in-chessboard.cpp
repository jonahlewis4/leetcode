class Solution {
    vector<pair<int, int>> dirs = {
        {1,2},
        {2,1},
        {-1, 2},
        {-2, 1},
        {1, -2},
        {2, -1},
        {-1, -2},
        {-2, -1}
    };

    //unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;
    vector<vector<vector<double>>> dp;
    int n;
    double search(int row, int column, int k){
        if(row < 0 || column < 0 || row >= n || column >= n) {
            return 0;
        }

        if(k == 0) {
            return 1;
        }
        

        if(dp[row][column][k - 1] != -1){
            return dp[row][column][k-1];
        }

        double res = 0;
        for(const pair<int, int> dir : dirs) {
            int newRow = row + dir.first;
            int newCol = column + dir.second;

            res += search(newRow, newCol, k - 1);
        }

        dp[row][column][k-1] = res / 8;
        return dp[row][column][k-1];
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        this->n = n;
        dp.resize(n, vector<vector<double>>(n, vector<double>(k, -1)));
        double res = search(row, column, k);
        //printDp();
        return res;
    }
};