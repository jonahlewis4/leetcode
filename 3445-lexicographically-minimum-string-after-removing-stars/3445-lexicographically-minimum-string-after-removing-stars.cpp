class Solution {
public:
    string clearStars(string s) {
        struct character {
            char c;
            int i;

            bool operator<(const character & other )const {
                //return true if lower priority.
                
                if(c < other.c) {
                    return false;
                }

                if(c > other.c) {
                    return true;
                }

                return i < other.i;
            }
        };
        priority_queue<character> pq;




        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            switch (c) {
                case '*':
                    //handle star
                    pq.pop();
                    break;
                default: 
                    //handle any character other than star
                    pq.push({
                        .c = c,
                        .i = i,
                    });
            }
                
        }
        
        vector<character> flatten(pq.size());
        for(int i = 0; i < flatten.size(); i++){
            flatten[i] = pq.top();
            pq.pop();
        }
        sort(flatten.begin(), flatten.end(), [](const auto & a, const auto & b) {
            return a.i < b.i;
        });

        string res(flatten.size(), '.');
        for(int i = 0; i < res.size(); i++){
            res[i] = flatten[i].c;
        }
        return res;
    }
};