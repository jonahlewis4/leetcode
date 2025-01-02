class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        std::vector<std::unordered_set<char>> rows(n);
        std::vector<std::unordered_set<char>> cols(n);
        std::vector<std::unordered_set<char>> subs(n);

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                char v = board[r][c];
                if(v == '.'){
                    continue;
                }
                int s = (r / 3) + ((c / 3) * 3);
                if(rows[r].find(v) != rows[r].end()){
                    return false;
                }
                if(cols[c].find(v) != cols[c].end()){
                    return false;
                }
                if(subs[s].find(v) != subs[s].end()){
                    return false;
                }

                rows[r].insert(v);
                cols[c].insert(v);
                subs[s].insert(v);
            }
        }
        return true;

    }
};