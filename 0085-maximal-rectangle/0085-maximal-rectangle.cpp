class Solution {
    static int largestRectangleInHistogram(vector<int>& hist) {
        stack<int> stack;
        stack.push(-1); 
        hist.push_back(0);

        int best = 0;
        for(int i = 0; i < hist.size(); i++) {
            int curHeight = hist[i];
            while(stack.top() != -1 && hist[stack.top()] > curHeight) {
                int popped = stack.top();
                stack.pop();
                int oldHeight = hist[popped];
                int width = i - stack.top() - 1;
                int area = oldHeight * width;
                best = max(best, area);

            }
            stack.push(i);
        }

        return best;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int best = 0;
        vector<int> histogram(matrix.front().size(), 0);
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix.front().size(); c++) {
                if(matrix[r][c] == '1') {
                    histogram[c]++;
                } else {
                    histogram[c] = 0;
                }
            }
            int largest = largestRectangleInHistogram(histogram);
            best = max(best, largest);
        }
        return best;
    }
};