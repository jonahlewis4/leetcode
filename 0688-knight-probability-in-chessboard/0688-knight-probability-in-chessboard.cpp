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

    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;
    int n;
    double search(int row, int column, int k){
        if(dp[row][column].contains(k)){
            return dp[row][column][k];
        }

        if(row < 0 || column < 0 || row >= n || column >= n) {
            return 0;
        }
        
        if(k == 0) {
            return 1;
        }

        double res = 0;
        for(const pair<int, int> dir : dirs) {
            int newRow = row + dir.first;
            int newCol = column + dir.second;

            res += search(newRow, newCol, k - 1);
        }

        dp[row][column][k] = res / 8;
        return dp[row][column][k];
    }
    void printDp(){
        for(const auto& [row, next] : dp){
            for(const auto & [col, next2] : next) {
                for(const auto & [k, paths] : next2){
                    cout<<"("<<row<<", "<<col<<") at k="<<k<<": "<<paths<<endl;
                }
            }
        }
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        this->n = n;
        double res = (double)search(row, column, k);
        //printDp();
        return res;
    }
};