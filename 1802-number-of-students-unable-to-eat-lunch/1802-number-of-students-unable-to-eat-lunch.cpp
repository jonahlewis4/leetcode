class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(const int i : students) {
            q.push(i);
        }

        stack<int> stack;
        for(int i = sandwiches.size() - 1; i >= 0; i--){
            stack.push(sandwiches[i]);
        }

        while(!stack.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                if(stack.top() != q.front()){
                    q.push(q.front());
                    q.pop();
                } else {
                    q.pop();
                    stack.pop();
                }
            }
            if(q.size() == n) {
                return q.size();
            }
        }

        return 0;
    }
};