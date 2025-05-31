class Solution {
    vector<int> flatten(const vector<vector<int>>& _board) const {
        int n = _board.size();
        int nSquared = n * n;
        vector<int> board(nSquared + 1);

        int boardI = 1;
        for(int r = n - 1; r >= 0; r--){
            for(int c = 0; c < n; c++){
                board[boardI] = _board[r][c];
                boardI++;
            }
            r--;
            if(r < 0){
                break;
            }
            for(int c = n - 1; c >= 0; c--){
                board[boardI] = _board[r][c];
                boardI++;
            }
        }
        return board;
    }
public:
    int snakesAndLadders(vector<vector<int>>& _board) {
        int n = _board.size();
        vector<int> board = flatten(_board);

        deque<int> q;
        vector<bool> enqueued(board.size(), false);
        q.push_back(1);
        enqueued[1] = true;
        int moves = 0;
        while(!q.empty()){
            int m = q.size();
            for(int i = 0; i < m; i++){
                int space = q.front();
                q.pop_front();
                if(space == n * n) {
                    return moves;
                }

                for(int j = space + 1; j <= space + 6; j++){
                    if(j > n * n){
                        continue;
                    }
                    int res = j;
                    if(board[j] != -1){
                        res = board[j];
                    }
                    if(enqueued[res]){
                        continue;
                    }
                    enqueued[res] = true;
                    q.push_back(res);
                }
            }
            moves++;
        }



        return -1;
    }
};