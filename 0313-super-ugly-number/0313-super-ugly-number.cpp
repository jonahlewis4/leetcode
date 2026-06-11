class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) {
            return 1;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        
        int last = -1;
        
        for(int i = 0; i < n - 1; i++) {
            int num = pq.top();
            pq.pop();
            if(num == last) {
                i--;
                continue;
            }
            for(int prime : primes) {
                if(INT_MAX/prime >= num) {
                    pq.push(num * prime);
                }
            }
            last = num;
        }

        while(pq.top() == last) {
            pq.pop();
        }
        return pq.top();
    }
};