class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> stk;
        int tabs = 0;
        int lastTabs = 0;
        int currentLength = 0;
        bool file = false;
        bool text = false;
        int longest = 0;
        stk.push(0);
        for(const char c : input) {
            if(c == '\t') {
                tabs++;
            } else if (c == '\n') {
                tabs = 0;
                file = false;
                text = false;

            } else {
                if(!text) {
                    if(tabs == lastTabs) {
                        currentLength = 0;
                    }
                    if(tabs > lastTabs) {
                        stk.push(currentLength + 1 + stk.top());
                        lastTabs++;
                        currentLength = 0;

                    }
                    while(lastTabs > tabs) {
                        currentLength = 0;
                        lastTabs--;
                        stk.pop();
                    }
                    text = true;
                }
                


                currentLength++;

                if(c == '.') {
                    file = true;
                }
                if(file) {
                    longest = max(longest, currentLength + stk.top());
                }
            }
            // cout<<c<<endl;
            // cout<<"tabs: "<<tabs<<endl;
            // cout<<"lastTabs: "<<lastTabs<<endl;
            // cout<<"current length: "<<currentLength<<endl;
            // cout<<"_________"<<endl;
        }

        return longest;
    }
};