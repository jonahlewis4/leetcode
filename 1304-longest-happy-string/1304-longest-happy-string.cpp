class Solution {
private:
    struct item {
        char c;
        int count;  
    };
public:
    string longestDiverseString(int a, int b, int c) {
        // a = 5, b = 4, c = 4
        // aabbccaabbcca

        // a = 9, b = 5
        // a = aa, b = 2
        // aabaabaabaab

        //priority queue. If we've pulled from top twice, get below

        priority_queue<item, vector<item>, decltype([](const auto & a, const auto & b){
            return a.count < b.count;
        })> pq;
        if(a > 0){
            pq.push({
                .c = 'a',
                .count = a,
            });
        }
        
        if(b > 0){
            pq.push({
                .c = 'b',
                .count = b,
            });
        }
        
        if(c > 0){
            pq.push({
                .c = 'c',
                .count = c,
            });
        }
        


        string res = "";
        int streak = 0;
        char prev = '@';
        while(!pq.empty()){
            item top = pq.top();
            pq.pop();
            if(top.c == prev){
                if(streak >= 2){
                    streak = 0;
                    if(pq.empty()){
                        return res;
                    }
                    item secondTop = pq.top();
                    pq.pop();
                    pq.push(top);
                    res.push_back(secondTop.c);
                    secondTop.count--;
                    if(secondTop.count > 0){
                        pq.push(secondTop);
                    }
                    prev = secondTop.c;
                    continue;
                }
            }
            prev = top.c;
            streak++;
            res.push_back(top.c);
            top.count--;
            if(top.count > 0){
                pq.push(top);
            }
        }
        return res;
    }
    

};