class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int sum = 0;
        int r = 0;
        int c = 0;
        while(r < n / 2){
            int rStart = r;
            int cStart = c;
            sum += mat[r][c];

            c = n - cStart - 1;
            sum += mat[r][c];


            r = n - rStart - 1;
            sum += mat[r][c];

            
            c = cStart;
            sum += mat[r][c]; 
           

            r = rStart;
            c = cStart;
            r++;
            c++;
        }

        if(n % 2 == 1) {
            sum += mat[n / 2][n/2];
        }
        return sum;
    }
};