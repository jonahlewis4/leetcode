class Solution {
public:
    int integerReplacement(int n) {
        int ops = 0;
        queue<int> q;
        

        if(n == INT_MAX){
            return 32;
        }
        q.push(n);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int num = q.front();
                q.pop();
                if(num == 1) {
                    return ops;
                }

                if(num % 2 == 0){
                    q.push(num / 2);
                } else {
                    q.push(num - 1);
                    q.push(num + 1);
                }
            }
            ops++;
        }

        return -1;
    }
};