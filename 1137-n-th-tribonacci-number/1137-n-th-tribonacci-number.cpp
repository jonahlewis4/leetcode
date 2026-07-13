class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 1;
        }
        int p3 = 0;
        int p2 = 1;
        int p1 = 1;

        for(int i = 3; i <= n; i++) {
            int next = p1 + p2 + p3;
            p3 = p2;
            p2 = p1;
            p1 = next;
        }

        return p1;
    }
};