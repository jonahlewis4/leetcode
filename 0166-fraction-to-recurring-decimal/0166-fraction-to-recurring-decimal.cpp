class Solution {
    
    long long denom;
    long long inside = 0;
   

    string GoTillPattern() {
        if (inside == 0) {
            return "";
        }
        string res = ".";
        unordered_map<long long, int> seen;

        int rStart = -1;
        int i = 1;
        while (inside != 0) {
            if (seen.contains(inside)) {
                rStart = seen[inside];
                break;
            }
            seen[inside] = i;
            inside *= 10;

            int div = inside / denom;
            res += div + '0';
            inside = inside % denom;
            i++;
        }

        if (rStart == -1) {
            return res;
        }
        return res.substr(0, rStart) + '(' + res.substr(rStart) + ')';
    }

public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        denom = labs(denominator);

        string sign;
        if (numerator < 0 ^ denominator < 0) {
            sign = "-";
        }

        long long num = labs(numerator);

        string before = to_string(num / denom);
        inside = num % denom;
        string after = GoTillPattern();
        return sign + before + after;
    }
};