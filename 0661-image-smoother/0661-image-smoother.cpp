class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<pair<int, int>> dirs = {
            {-1,-1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 0},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1},
        };

        vector<vector<int>> res(img.size(), vector<int>(img.front().size()));

        for(int r = 0; r < img.size(); r++) {
            for(int c = 0; c < img.front().size(); c++) {
                int total = 0;
                int used = 0;
                for(const pair<int, int> dir : dirs) {
                    int xDelta = dir.first;
                    int yDelta = dir.second;
                    int newR = r + xDelta;
                    int newC = c + yDelta;

                    if(newR < 0 || newC < 0 || newR >= img.size() || newC >= img.front().size()) {
                        continue;
                    }
                    used++;
                    total += img[newR][newC];
                }

                res[r][c] = total/used;
            }
        }

        return res;
    }
};