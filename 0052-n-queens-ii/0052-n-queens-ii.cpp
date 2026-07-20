class Solution {
    int total = 0;
    int n = 0;
    vector<bool> cols;
    vector<bool> sumDiag;
    vector<bool> diffDiag;
    bool valid(int row, int col) const {
        if(cols[col]) {
            return false;
        }
        if(sumDiag[row+col]) {
            return false;
        }
        if(diffDiag[row-col+n-1]){
            return false;
        }
        return true;
    }

    void set(int row, int col) {
        cols[col] = true;
        sumDiag[row+col] = true;
        diffDiag[row-col+n-1] = true;
    }
    void unset(int row, int col) {
        cols[col] = false;
        sumDiag[row+col] = false;
        diffDiag[row-col+n-1] = false;
    }

    void r(int row) {
        if(row == n) {
            total++;
            return;
        }
        for(int c = 0; c < n; c++) {
            //if a queen can go in this spot, add it, go down a row, then backtrack
            if(valid(row,c)){
                set(row,c);
                r(row+1);
                unset(row,c);
            }
        }
    }
public:
    int totalNQueens(int n) {
        cols.resize(n, false);
        sumDiag.resize(n*2-1, false);
        diffDiag.resize(n*2-1, false);
        this->n = n;
        r(0);
        return total;
    }
};