class Solution {
private:
    vector<tuple<int, int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int unrotten = 0;
        queue<tuple<int, int>> rotting;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 2){
                    rotting.push({row, col});
                }   
                if(grid[row][col] == 1){
                    unrotten++;
                }
            }
        }
        int minutes = 0;
        while(unrotten > 0 && !rotting.empty()){
            int n = rotting.size();
            minutes++;
            for(int i = 0; i < n; i++){
                auto [_x, _y] = rotting.front();
                rotting.pop();
                for(const auto dir : dirs){
                    auto [xOffset, yOffset] = dir;
                    int x = _x + xOffset;
                    int y = _y + yOffset;
                    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size()){
                        continue;
                    }

                    if(grid[x][y] == 1){
                        rotting.push({x, y});
                        grid[x][y] = 2;
                        unrotten--;
                    }
                    if(unrotten == 0){
                        return minutes;
                    }
                }
            }
        }
        if(unrotten > 0){
            return -1;
        }
        return minutes;

    }
};