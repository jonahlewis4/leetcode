class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> res(boxGrid[0].size(), 
            vector<char>(boxGrid.size(), '.')
        );

        for(int ogR = 0; ogR < boxGrid.size(); ogR++) {
            for(int ogC = 0; ogC < boxGrid[0].size(); ogC++) {
                res[ogC][boxGrid.size() - 1 - ogR] = boxGrid[ogR][ogC];
            }
        }

        for(int c = 0; c < res[0].size(); c++) {
            int nextAvailRow = res.size() - 1;
            for(int r = res.size() - 1; r >= 0; r--){
                char curChar = res[r][c];
                switch (curChar) {
                    case '#':
                        res[nextAvailRow][c] = curChar;
                        if(nextAvailRow != r) {
                            res[r][c] = '.';
                        }
                        nextAvailRow--;
                        break;
                    case '*':
                        nextAvailRow = r - 1;
                        break;
                    case '.':
                        break;
                }
            }
        }

        return res;

    }
};