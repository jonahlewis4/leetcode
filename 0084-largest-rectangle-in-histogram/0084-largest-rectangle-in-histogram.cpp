class Solution {
private:
    struct chain{
        int index;
        int start;
    };
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<chain> stack;
        int maxArea = 0;
        
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            int min = i;
            while(!stack.empty() && heights[stack.top().index] > heights[i]){
                int area = (i - stack.top().start) * heights[stack.top().index];
                maxArea = max(area, maxArea);
                min = stack.top().start;
                stack.pop();
            }
            stack.push({i, min});
        }
        return maxArea;
    }
};