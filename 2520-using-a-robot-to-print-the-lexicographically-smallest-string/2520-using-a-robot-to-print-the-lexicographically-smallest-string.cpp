class Solution {
public:
    string robotWithString(string s) {
        vector<char> smallestAfter(s.size());
        char smallest = s.back();
        smallestAfter.back() = 'a' - 1;
        for(int i = s.size() - 2; i >= 0; i--){
            smallestAfter[i] = smallest;
            smallest = min(smallest, s[i]);
        }

        stack<int> t;
        string p = "";

        for(int i = 0; i < s.size(); i++){
            if(t.empty() ||  s[t.top()] > smallestAfter[i - 1]){
                t.push(i);
            } else {
                int topI = t.top();
                t.pop();
                p.push_back(s[topI]);
                i--;
            }
        }

        while(!t.empty()){
            p.push_back(s[t.top()]);
            t.pop();
        }
        return p;

    }
};