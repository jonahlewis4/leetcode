class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string blankCol(n, '.');
        vector<string> cur(n, blankCol);
        vector<vector<string>> res;
        vector<tuple<int, int>> queens;
        calc(cur, res, 0, queens);
        return res;
    }
    void calc (vector<string>& cur, 
    vector<vector<string>> &res, int i, vector<tuple<int, int>> &queens){
            int n = cur.size();
            if(i >= n){
                res.push_back(cur);
                return;
            }

            for(int row = 0; row < n; row++){
                if(noConflicts(row, i, queens)){
                    queens.push_back({row, i});
                    cur[row][i] = 'Q';
                    calc(cur, res, i + 1, queens);
                    cur[row][i] = '.';
                    queens.pop_back();
                }
            }
        }

    bool noConflicts(int row, int col, vector<tuple<int, int>>& queens){
        for(const auto & queen : queens){
            const auto [existingRow, existingCol] = queen;
            if(existingRow == row){
                return false;
            }
            if(existingCol == col){
                return false;
            }
            if(abs(existingCol - col) == abs(existingRow - row)){
                return false;
            }
        }
        return true;
    }
};