class Solution {
    int ltEq(vector<vector<int>>& matrix, int val) {
        int total = 0;
        for(const vector<int>& row : matrix) {
            for(const int x : row) {
                if(x <= val) {
                    total++;
                }
            }
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