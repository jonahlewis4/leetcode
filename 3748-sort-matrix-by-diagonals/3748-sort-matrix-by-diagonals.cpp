class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int r = grid.size(); r >= 0; r--) {
            vector<int> temp;
            int dR = r;
            int dC = 0;
            while(dR < grid.size()) {
                temp.push_back(grid[dR][dC]);
                dR++;
                dC++;
            }
            sort(temp.begin(), temp.end(), [](int a, int b){
                return a > b;
            });

            for(int i = 0; i < temp.size(); i++) {
                grid[r + i][i] = temp[i];
            }
        }
        
        for(int c = 1; c < grid.front().size(); c++) {
            vector<int> temp;
            int dR = 0;
            int dC = c;

            while(dC < grid.front().size()) {
                temp.push_back(grid[dR][dC]);
                dR++;
                dC++;
            }
            sort(temp.begin(), temp.end());

            for(int i = 0; i < temp.size(); i++) {
                grid[i][c + i] = temp[i];
            }
        }

        return grid;
    }
};