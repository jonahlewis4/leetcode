class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> left(matrix.front().size(), 0);
        vector<int> right(matrix.front().size(), matrix.front().size());
        vector<int> h(matrix.front().size(), 0);
        int best = 0;
        for(int r = 0 ; r < matrix.size(); r++) {
            //update heights
            for(int c = 0; c < matrix.front().size(); c++) {
                if(matrix[r][c] == '1') {
                    h[c]++;
                } else {
                    h[c] = 0;
                }
            }

            //update to most restrictive boundary
            int lastZero = -1;
            for(int c = 0; c < matrix.front().size(); c++) {
                if(matrix[r][c] == '1') {
                    left[c] = max(lastZero + 1, left[c]);
                } else {
                    left[c] = 0;
                    lastZero = c;
                }
            }   

            lastZero = matrix.front().size();

            for(int c = matrix.front().size() - 1; c >= 0; c--) {
                if(matrix[r][c] == '1') {
                    right[c] = min(lastZero-1, right[c]);
                } else {
                    right[c] = matrix.front().size() - 1;
                    lastZero = c;
                }

                int width = right[c] - left[c] + 1;
                int area = h[c] * width;
                best = max(area, best);
                
            }
            
        }
        return best;
    }
};