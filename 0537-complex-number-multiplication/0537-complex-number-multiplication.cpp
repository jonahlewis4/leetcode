class Solution {
    struct ComplexNumber {
        int imaginary;
        int real;
        ComplexNumber(string& num) {
            int i = 0;
            while(num[i] != '+') {
                i++;
            }
            real = stoi(num.substr(0, i));
            i++;
            int complexStart = i;
            while(num[i] != 'i') {
                i++;
            }
            imaginary = stoi(num.substr(complexStart, i - complexStart));
        }

        ComplexNumber(int real, int imaginary) {
            this->real = real;
            this->imaginary = imaginary;
        }

        ComplexNumber operator*(const ComplexNumber& rhs) const {
            const ComplexNumber *const lhs = this;
            int newReal = lhs->real * rhs.real;
            int newReal2 = -lhs->imaginary * rhs.imaginary;
            int newComplex = lhs->real * rhs.imaginary;
            int newComplex2 = lhs->imaginary * rhs.real;
            return ComplexNumber(newReal + newReal2, newComplex + newComplex2);
        }

        string toString() const {
            return to_string(real) + "+" + to_string(imaginary) + "i";
        }

        
    };
public:
    string complexNumberMultiply(string num1, string num2) {
        ComplexNumber c1(num1);
        ComplexNumber c2(num2);

        ComplexNumber result = c1 * c2;
        return result.toString();
    }
};