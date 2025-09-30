class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(const int i : students) {
            q.push(i);
        }
        int j = 0;
        while(j < sandwiches.size()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                if(sandwiches[j] != q.front()){
                    q.push(q.front());
                    q.pop();
                } else {
                    q.pop();
                    j++;
                }
            }
            if(q.size() == n) {
                return q.size();
            }
        }

        return 0;
    }
};