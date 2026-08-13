class Solution {
    int ltEq(vector<vector<int>>& matrix, int val) {
        int total = 0;
        int c = matrix.size() - 1;
        for(int r = 0; r < matrix.size(); r++) {
            while(c >= 0 && matrix[r][c] > val) {
                c--;
            }
            total += c + 1;
        }
        return total;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix.front().front();
        int r = matrix.back().back();
        int res = r;
        while(l <= r) {
            int m = l + (r-l)/2;
            
            int lessOrEqual = ltEq(matrix, m);
            if(lessOrEqual >= k) {
                r = m - 1;
                res = m;
            } else {
                l = m + 1;
            }
        }

        return res;

        
    }
};