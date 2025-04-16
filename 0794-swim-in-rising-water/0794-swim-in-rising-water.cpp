class Solution {
    struct qItem {
        int r;
        int c;
        int depth;
    };
    vector<tuple<int, int>> dirs = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        //bfs with visited. 
        //if water is not high enough push it and deal with it later.
        queue<qItem> q;
        q.push({
            .r = 0,
            .c = 0,
            .depth = grid[0][0]
        });
        int t = 0;
        while(!q.empty()){
            int n = q.size();
            int reached = 0;
            for(int i = 0; i < n; i++){
                qItem item = q.front();
                q.pop();
                
                if(item.depth > t){
                    q.push(item);
                    continue;
                } 
                reached++;

                if(grid[item.r][item.c] < 0){
                    continue;
                }  

                if(item.r == grid.size() - 1 && item.c == grid[0].size() - 1){
                    return t;
                }
                grid[item.r][item.c] = -1;

                for(const auto & dir : dirs){
                    auto [rOff, cOff] = dir;
                    int newR = item.r + rOff;
                    int newC = item.c + cOff;
                    if(newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[newR].size()){
                        continue;
                    }
                    q.push({
                        .r = newR,
                        .c = newC,
                        .depth = grid[newR][newC]
                    });
                }
            }
            if(reached == 0){
                t++;
            }
        }

        return -1;

    }
};