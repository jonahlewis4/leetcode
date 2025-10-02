class Solution {
    enum Ops {
        PLUS = -1,
        MINUS = -2,
        MULT = -3,
    };
    static vector<int> parse(const string& e) {
        vector<int> tokens;
        string numberStr;
        for(const char c : e) {
            if(!isdigit(c)) {
                tokens.push_back(stoi(numberStr));
                numberStr = "";
                switch (c) {
                    case '-':
                        tokens.push_back(MINUS);
                        break;
                    case '+':
                        tokens.push_back(PLUS);
                        break;
                    default:
                        tokens.push_back(MULT);
                }
            } else {
                numberStr += c;
            }
        }
        tokens.push_back(stoi(numberStr));

        return tokens;
    }
    vector<int> tokens;
    vector<int> eval(int l, int r) {
        if(l == r) {
            return {tokens[l]};
        }
        vector<int> res;
        for(int i = l + 2; i <= r; i += 2) {
            vector<int> lArr = eval(l, i - 2);
            vector<int> rArr = eval(i, r);
            Ops op = (Ops)tokens[i - 1];

            for(const int lVal : lArr) {
                for (const int rVal : rArr) {
                    int combination = lVal;
                    switch (op) {
                        case MINUS:
                            combination -= rVal;
                            break;
                        case PLUS:
                            combination += rVal;
                            break;
                        default:
                            combination *= rVal;
                        
                    }
                    res.push_back(combination);
                }
            }
        }
        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> tokens = parse(expression);
        this->tokens = tokens;
        return eval(0, tokens.size() - 1);
        
    }
};