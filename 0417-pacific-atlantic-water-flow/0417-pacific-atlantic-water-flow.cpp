class Solution {
private: vector<vector<bool>> visit;
    vector<vector<int>> heights;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        visit = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size(), false));
        this->heights = heights;

        for(int c = 0; c < heights[0].size(); c++){
            dfs(0, c, pacific, 0);
            dfs(heights.size() - 1, c, atlantic, 0);
        }

        for(int r = 0; r < heights.size(); r++){
            dfs(r, 0, pacific, 0);
            dfs(r, heights[r].size() - 1, atlantic, 0);
        }        
        
        vector<vector<int>> res;
        for(int r = 0; r < heights.size(); r++){
            for(int c = 0; c < heights[r].size(); c++){
                if(pacific[r][c] && atlantic[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, int prev){
        if(r < 0 || c < 0 || r >= ocean.size() || c >= ocean[r].size()){
            return;
        }
        if(heights[r][c] < prev){
            return;
        }
        if(visit[r][c]){
            return;
        }

        //TODO if already set to true, exit
        if(ocean[r][c] == true){
            return;
        }

        ocean[r][c] = true;

        visit[r][c] = true;

        prev = heights[r][c];
        dfs(r - 1, c, ocean, prev);
        dfs(r + 1 ,c, ocean, prev);
        dfs(r, c - 1, ocean, prev);
        dfs(r, c + 1, ocean, prev);
        visit[r][c] = false;
    }
};