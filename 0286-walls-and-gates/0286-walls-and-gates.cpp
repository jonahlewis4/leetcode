class Solution {
private:
    vector<tuple<int, int>> dirs = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<tuple<int, int, int>> q;
        
        for(int r = 0; r < rooms.size(); r++){
            for(int c = 0; c < rooms[r].size(); c++){
                if(rooms[r][c] == 0){
                    q.push({r, c, 0});
                }
            }
        }

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto [r, c, dst] = q.front();
                q.pop();


                for(const auto & dir : dirs){
                    auto [xOffset, yOffset] = dir;
                    int newR = r + xOffset;
                    int newC = c + yOffset;

                    if(newR < 0 || newC < 0 || newR >= rooms.size() || newC >= rooms[newR].size()){
                        continue;
                    }
                    if(rooms[newR][newC] == 0 || rooms[newR][newC] == -1 || rooms[newR][newC] < INT_MAX){
                        continue;
                    }


                    rooms[newR][newC] = dst + 1;
                    q.push({newR, newC, dst + 1});
                }
            }
        }
    }
};