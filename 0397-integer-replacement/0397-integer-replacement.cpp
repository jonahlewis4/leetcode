class Solution {
public:
    int integerReplacement(int n) {
        int ops = 0;
        queue<int> q;
        

        if(n == INT_MAX){
            return 32;
        }
        q.push(n);

        unordered_set<int> enqueued;
        enqueued.insert(n);
        
        const auto & add = [&enqueued, &q](int next) {
            if(!enqueued.contains(next)) {
                enqueued.insert(next);
                q.push(next);
            }
        };

        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int num = q.front();
                q.pop();
                if(num == 1) {
                    return ops;
                }
                
            

                if(num % 2 == 0){
                    int next = num / 2;
                    add(next);
                } else {
                    int down = num - 1;
                    int up = num + 1;
                    add(down);
                    add(up);

                }
            }
            ops++;
        }

        return -1;
    }
};