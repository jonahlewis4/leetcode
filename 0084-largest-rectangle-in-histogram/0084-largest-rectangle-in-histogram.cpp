class Solution {
private:
    struct chain{
        int index;
        int start;
    };
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> stack;
        stack.push(-1);
        heights.push_back(0);
        int maxHeight = 0;
        for(int i = 0; i < heights.size(); i++){
            while(stack.top() != -1 && heights[stack.top()] > heights[i]){
                int height = heights[stack.top()];
                stack.pop();
                int width =  i - (stack.top() + 1);
                int area = width * height;
                maxHeight = max(area, maxHeight);
            }
            stack.push(i);
        }
        return maxHeight;
    }
};