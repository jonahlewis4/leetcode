class Solution {
public:
    int largestRectangleArea(vector<int>& hist) {
        stack<int> stack;
        stack.push(-1);

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

        while(stack.top() != -1) {
            int popped = stack.top();
            stack.pop();
            int height = hist[popped];
            int width = hist.size() - stack.top() - 1;
         
            int area = height * width;
            best = max(best, area);
        }

        return best;
    }
};