class Solution {
    class DigitExtractor {
        long long r = 0;
        int i = 0;
        int c = 0;

    public:
        DigitExtractor() { r = 0; }
        DigitExtractor(long long n) {
            r = 0;
            while (n > 0) {
                r *= 10;
                r += n % 10;
                n /= 10;
                c++;
            }
        }

        int getNext() {
            const auto& _r = r;
            int res = r % 10;
            r /= 10;
            i++;
            return res;
        }

        bool digitEnd() const { return i >= c; }
    };
    string res = "";
    DigitExtractor nExtract;
    long long denom;
    long long inside = 0;
    string GoTillDeci() {
        string res = "";
        while (!nExtract.digitEnd()) {
            inside *= 10;
            inside += nExtract.getNext();

            int div = inside / denom;

            res.push_back(div + '0');
            if (res.size() == 1 && res.front() == '0') {
                res.pop_back();
            }

            inside = inside % denom;
        }
        return res == "" ? "0" : res;
    }

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

        nExtract = DigitExtractor(labs(numerator));
        denom = labs(denominator);

        string sign;
        if (numerator < 0 ^ denominator < 0) {
            sign = "-";
        }

        string before = GoTillDeci();
        string after = GoTillPattern();
        return sign + before + after;
    }
};