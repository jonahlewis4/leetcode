class Solution {

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        struct Log {
            int id;
            int start = -1;
            int end = -1;
        };
        const auto & stoiL = [](const string& s) {
            Log res;
            int i = 0;
            while(s[i] != ':'){
                i++;
            }
            string idStr = s.substr(0, i);
            i++;
            res.id = stoi(idStr);

            int* dest = &res.start;
            if(s[i] == 'e'){
                dest = &res.end;
            }

            while(s[i] != ':'){
                i++;
            }
            i++;

            *dest = stoi(s.substr(i, s.size() - i));
            return res;
        };
        stack<int> stack;
        int lastSwitch = 0;
        for(const auto & log : logs) {
            Log l = stoiL(log);
            if(l.start != -1){
                if(!stack.empty()){
                    int running = stack.top();
                    res[running] += l.start - lastSwitch;

                }
                lastSwitch = l.start;
                stack.push(l.id);

            } else {
                int running = stack.top();
                stack.pop();
                res[running] += l.end + 1 - lastSwitch;
                lastSwitch = l.end + 1;
            }
        } 
        return res;
    }
};