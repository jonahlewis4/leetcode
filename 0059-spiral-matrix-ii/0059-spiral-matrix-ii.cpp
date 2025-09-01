class Solution {
    struct dir {
        const int r;
        const int c;
    };
    vector<dir> dirs = {
        {
            .r = 0,
            .c = 1
        },
        {
            .r = 1,
            .c = 0
        },
        {
            .r = 0,
            .c = -1
        },
        {
            .r = -1,
            .c = 0
        }
    };
    vector<vector<int>> ans;
    dir* cDir = &dirs[0];
    int dirI;
    int moveCount;
    int totalMoves;
    int r;
    int c;
    void exhaustMoveCount() {
        for(int i = 0; i < moveCount; i++) {
            const auto & [rChange, cChange] = *cDir;
            r += rChange;
            c += cChange;
            totalMoves++;
            ans[r][c] = totalMoves + 1;
        }
    }
    void pivot() {
        cDir = &dirs[++dirI % 4];
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        ans.resize(n, vector<int>(n));

        r = 0;
        c = 0;
        ans[r][c] = 1;
        totalMoves = 0;
        moveCount = n - 1;
        dirI = 0;
        const auto & v = ans;
        bool first = true;
        while(moveCount > 0) {
            int exhausts = first ? 3 : 2;
            for(int i = 0; i < exhausts; i++) {
                exhaustMoveCount();
                pivot();
            }
            moveCount--;
            first = false;
        }

        return ans;
    }
};