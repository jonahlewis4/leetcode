class Solution {
    class Expression{
        class Term{
        public:
            int coefficient=0;
            bool isX=0;
        };
        class Parser{
            const string& s;
            int i = 0;
        public:
            Parser(const string& s) : s(s) {
                
            }

            bool hasNext() const {
                return i < s.size();
            }
            Term getNext() {
                int sign = 1;
                if(s[i] == '+' || s[i] == '-'){
                    sign = s[i] == '+' ? 1 : -1;
                    i++;
                }
                int start = i;
                int val=0;
                while(i < s.size() && isdigit(s[i])){
                    val *= 10;
                    val += s[i] - '0';
                    i++;
                }

                if(i == start) {
                    val = 1;
                }

                bool isX = false;
                if(i < s.size() && s[i] == 'x'){
                    isX = true;
                    i++;
                }

                return Term{sign * val, isX};
            }
        };

    public:
        int xCoef=0;
        int cCoef=0;
        Expression(const string& s) {
            Parser p(s);
            while(p.hasNext()) {
                Term t = p.getNext();
                if(t.isX){
                    xCoef += t.coefficient;
                } else {
                    cCoef += t.coefficient;
                }
            }
        }
    };

    class Equation{
        Expression lhs;
        Expression rhs;
    public:
        Equation(const string& s) : 
            lhs(s.substr(0, s.find("="))),
            rhs(s.substr(s.find("=") + 1)) {}

        string solve() {
            lhs.xCoef-=rhs.xCoef;
            rhs.cCoef-=lhs.cCoef;

            int x = lhs.xCoef;
            int c = rhs.cCoef;

            if(x != 0) {
                return "x="+to_string(c/x);
            }
            if(c == 0) {
                return "Infinite solutions";
            }
            return "No solution";
            
        }
    };
public:
    string solveEquation(string equation) {
        
        Equation e(equation);
        return e.solve();
    }
};