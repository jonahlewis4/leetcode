class Solution {
private:
vector<vector<int>> _grid;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        _grid = grid;
        int maxArea = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                int area = calc(row, col);
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
    int calc(int row, int col) {
        if(row < 0 || col < 0 || row >= _grid.size() || col >=_grid[row].size()){
            return 0;
        }
        if(_grid[row][col] == 0){
            return 0;
        }
        _grid[row][col] = 0;
        int totalArea = 1;
        totalArea += calc(row + 1, col);
        totalArea += calc(row - 1, col);
        totalArea += calc(row, col + 1);
        totalArea += calc(row, col - 1);
        return totalArea;
    }
};