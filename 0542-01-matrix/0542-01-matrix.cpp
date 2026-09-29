class Solution {
    vector<pair<int, int>> dirs = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> res(mat.size(), vector<int>(mat.front().size(), -1));
        for(int r = 0; r < mat.size(); r++) {
            for(int c = 0; c < mat.front().size(); c++) {
                if(mat[r][c] == 0) {
                    q.push({r,c});
                    res[r][c] = 0;
                }
            }
        }

        for(int i = 0; !q.empty(); i++) {
            int n = q.size();
            for(int j = 0; j < n; j++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(const pair<int, int> dir : dirs) {
                    int newR = r + dir.first;
                    int newC = c + dir.second;
                    if(newR < 0 || newC < 0 || newR >= mat.size() || newC >= mat.front().size()){
                        continue;
                    }
                    if(res[newR][newC] == -1) {
                        res[newR][newC] = i + 1;
                        q.push({newR, newC});
                    }
                }
            }
        }


        return res;
    }
};