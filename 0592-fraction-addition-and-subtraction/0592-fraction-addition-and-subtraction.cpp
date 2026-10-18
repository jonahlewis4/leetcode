class Solution {
    class Fraction{
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator){
            reduce();
        }

        Fraction& operator+=(const Fraction& other) {
            *(this) = (*this)+other;
            return *this;
        }
        Fraction operator+(const Fraction& other) const {
            int leastCommonMult = lcm(this->denominator, other.denominator);
            int scale1 = leastCommonMult / this->denominator;
            int scale2 = leastCommonMult / other.denominator;

            int newNumerator = this->numerator * scale1 + other.numerator * scale2;
            
            return Fraction(newNumerator, leastCommonMult);
        }

        string toString() const {
            return to_string(numerator) + "/" + to_string(denominator);
        }

        friend ostream& operator<<(ostream& out, const Fraction& f) {
            return out<<f.toString();
        }

        void reduce() {
            int divisor = gcd(numerator, denominator);
            numerator /= divisor;
            denominator /= divisor;
        }
    };

    class Parser {
        const string& s;
        int i = 0;
    public:
        Parser(const string& s) : s(s) {}

        bool hasNext() const {
            return i < s.size();
        }
        Fraction getNext(){
            int start = i;
            i++;
            while(s[i] != '/'){
                i++;
            }

            int numerator = stoi(s.substr(start, i - start));
            i++;
            int start2 = i;
            i++;
            while(i < s.size() && s[i] != '+' && s[i] != '-'){
                i++;
            }

            int denominator = stoi(s.substr(start2, i - start2));
            Fraction res(numerator, denominator);
            return res;
        }    
    };

public:
    string fractionAddition(string expression) {
        Parser p(expression);
        Fraction total(0,1);
        while(p.hasNext()) {
            Fraction f = p.getNext();
            cout<<f<<endl;
            total += f;
        }

        return total.toString();
    }
};