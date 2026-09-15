class Solution {
public:
    int magicalString(int n) {
        //0 = 1;
        //1 = 2

        if(n <= 3) {
            return 1;
        }
        uint8_t twoMode = 0;
        
        queue<uint8_t> q;
        q.push(1);
        int total = 1;
        for(int i = 3; i < n; i++) {
            uint8_t amountToAppend = q.front() + 1;
            for(int j = 0; j < amountToAppend; j++) {
                q.push(twoMode);
            }
            q.pop();
            if(!q.front()) {
                total++;
            }
            twoMode = !twoMode;
        }
        
        return total;
    }
};