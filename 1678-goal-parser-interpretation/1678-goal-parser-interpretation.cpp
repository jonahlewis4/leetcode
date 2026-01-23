class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i = 0; i < command.size(); i++){
            char c = command[i];
            if(c == 'G'){
                res += c;
                continue;
            }
            i++;
            char nextC = command[i];
            if(nextC == ')'){
                res += 'o';
                continue;
            }

            res += "al";
            i += 2;
        }

        return res;
    }
};