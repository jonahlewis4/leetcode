class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogVal = image[sr][sc];
        if(ogVal == color) {
            return image;
        }
        vector<pair<int, int>> dirs = {
            {-1,0},
            {1, 0},
            {0,1},
            {0,-1},
        };

        stack<pair<int, int>> stack;
        stack.push({sr, sc});
        
        image[sr][sc] = color;

        while(!stack.empty()) {
            pair<int, int> point = stack.top();
            stack.pop();

            int r = point.first;
            int c = point.second;

            for(const pair<int, int>& dir : dirs) {
                int rDelta = dir.first;
                int cDelta = dir.second;
                int newR = r + rDelta;
                int newC = c + cDelta;

                if(newR < 0 || newC < 0 || newR >= image.size() || newC >= image.front().size()) {
                    continue;
                }

                if(image[newR][newC] == ogVal) {
                    image[newR][newC] = color;
                    stack.push({newR, newC});
                }
            }
        }

        return image;
    }
};