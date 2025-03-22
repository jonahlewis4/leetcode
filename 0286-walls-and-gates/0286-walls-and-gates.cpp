class Solution {
private:
    const int INF = 2147483647;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        std::queue<tuple<int, int, int>> gates;
        for(int row = 0; row < rooms.size(); row++){
            for(int col = 0; col < rooms[row].size(); col++){
                if(rooms[row][col] == 0){
                    gates.push({row + 1, col, 0});
                    gates.push({row - 1, col, 0});
                    gates.push({row, col + 1, 0});
                    gates.push({row, col - 1, 0});
                }
            }
        }

        while(!gates.empty()){
            int n = gates.size();
            for(int i = 0; i < n; i++){
                auto [x,y, dist] = gates.front();
                gates.pop();
                if(x < 0 || y < 0 || x >= rooms.size() || y >= rooms[x].size()){
                    continue;
                }
                if(rooms[x][y] == INF){
                    rooms[x][y] = dist + 1;
                    gates.push({x + 1, y, dist + 1});
                    gates.push({x - 1, y, dist + 1});
                    gates.push({x, y + 1, dist + 1});
                    gates.push({x, y - 1, dist + 1});
                }
            }
        }
    }
};