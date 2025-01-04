class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        for(const auto & token: tokens){
                if(token == "+"){
                    int e1 = stack.top();
                    stack.pop();
                    int e2 = stack.top();
                    stack.pop();
                    stack.push(e1 + e2);
                    continue;
                }
                if(token == "-") {
                    int e1 = stack.top();
                    stack.pop();
                    int e2 = stack.top();
                    stack.pop();
                    stack.push(e2 - e1);
                    continue;
                }
                if(token == "*"){
                    int e1 = stack.top();
                    stack.pop();
                    int e2 = stack.top();
                    stack.pop();
                    stack.push(e1 * e2);
                    continue;
                }
                if(token == "/"){
                    int e1 = stack.top();
                    stack.pop();
                    int e2 = stack.top();
                    stack.pop();
                    stack.push(e2 / e1);
                    continue;
                }
                else {
                    stack.push(stoi(token));
                }
            }
        
        return stack.top();

    }
};