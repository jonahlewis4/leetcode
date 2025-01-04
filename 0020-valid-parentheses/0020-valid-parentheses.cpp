class Solution {
private:
    unordered_map<char, char> map = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for(const auto & c : s){
            if(map.find(c) != map.end()){
                stack.push(c);
                continue;
            } else if (stack.empty()){
                return false;
            } else if (map[stack.top()] != c){
                return false;
            }
            stack.pop();
        }
        return stack.empty();
    }
};