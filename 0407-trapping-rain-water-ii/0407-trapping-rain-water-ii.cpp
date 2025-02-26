
class Solution {
private: 
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const auto cmp = [](const auto & a, const auto & b){
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
        int rc = heightMap.size();
        int cc = heightMap[0].size();
        vector<vector<int>> visited(rc, vector<int>(cc, 0));

        for(int col = 0; col < cc; col++){
            pq.push({heightMap[0][col], 0, col});
            visited[0][col] = 1;
            pq.push({heightMap[rc - 1][col], rc - 1, col});
            visited[rc - 1][col] = 1;
        }

        for(int row = 1; row < rc - 1; row++){
            pq.push({heightMap[row][0], row, 0});
            visited[row][0] = 1;
            pq.push({heightMap[row][cc - 1], row, cc - 1});
            visited[row][cc - 1] = 1;
        }

        int maxHeight = 0;
        
        int water = 0;
        while(!pq.empty()){
            const auto top = pq.top();
            pq.pop();
            maxHeight = max(maxHeight, top[0]);
            int depth = maxHeight - top[0];
            water += depth;

            int row = top[1];
            int col = top[2];

            
            if(row - 1 >= 0 && !visited[row - 1][col]){
                pq.push({heightMap[row - 1][col], row - 1, col});
                visited[row - 1][col] = 1;
            }
            if(col - 1 >= 0 && !visited[row][col - 1]){
                pq.push({heightMap[row][col - 1], row, col - 1});
                visited[row][col - 1] = 1;
            }
            if(row + 1 < rc && !visited[row + 1][col]){
                pq.push({heightMap[row + 1][col], row + 1, col});
                visited[row + 1][col] = 1;
            }
            if(col + 1 < cc && !visited[row][col + 1]){
                pq.push({heightMap[row][col + 1], row, col + 1});
                visited[row][col + 1] = 1;
            }

            
        }
        return water;
    }
};
