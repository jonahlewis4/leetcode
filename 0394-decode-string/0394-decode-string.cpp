class Solution {
public:
    string decodeString(string s) {
        

        std::stack<char> stk;

        for (const char c : s){
            if(c != ']'){
                stk.push(c);
            } else {
                string localDecode = "";
                while(!stk.empty() && stk.top() != '['){
                    localDecode += stk.top();
                    stk.pop();
                }
                if(!stk.empty()) {stk.pop();}
                string localNum = "";
                while(!stk.empty() && isdigit(stk.top())){
                    localNum += stk.top();
                    stk.pop();
                }
                reverse(localNum.begin(), localNum.end());
                int num = 1;
                if(localNum != ""){
                    num = stoi(localNum);
                }
                for(int j = 0; j < num; j++){
                    for(int i = localDecode.size() - 1; i >= 0; i--){
                        stk.push(localDecode[i]);
                    }
                }
                    
            }
        }

        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;

    }
};