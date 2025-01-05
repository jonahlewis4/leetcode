class Solution {
private:
    struct temperature{
        int temp;
        int index;
    };
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<temperature> stack;
        std::vector<int> res(temperatures.size(), 0);
        int i = 0;
        for(const auto & temp : temperatures){
            while(!stack.empty() && stack.top().temp < temp){
                res[stack.top().index] = i - stack.top().index;
                stack.pop();
            }
            stack.push({temp, i});
            i++;
        }
        return res; 
    }
};