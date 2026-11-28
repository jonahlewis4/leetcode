class Solution {
    bool isEmail(const string& s) {
        return s.find('@') != string::npos;
    }
    string maskEmail(const string& s){
        string res;
        res += tolower(s.front());
        res += "*****";
        int atIdx = s.find('@');
        res += tolower(s[atIdx - 1]);
        res += "@";
        int lowerStart = res.size();
        res += s.substr(atIdx + 1);
        for(int i = lowerStart; i < res.size(); i++) {
            res[i] = tolower(res[i]);
        }
        return res;
    }

    class PhoneNumber{
        string countryCode = "";
        string remaining = "";

    public:
        PhoneNumber(const string& s){
            string& end = remaining;
            int i = s.size() - 1;
            for(int found = 0; found < 10; i--) {
                if(isdigit(s[i])){
                    found++;
                    if(end.size() < 4) {
                        end += s[i];
                    }
                }
            }
            reverse(remaining.begin(), remaining.end());

            for(int j = 0; j <= i; j++) {
                if(isdigit(s[j])){
                    countryCode += '*';
                }
            }
        }

        string redact() const {
            string endAppend = "***-***-" +
                remaining;
            switch (countryCode.size()){
                case 0: 
                    return endAppend;
                default:
                    return "+" + countryCode + "-" + endAppend;
            }
        }
    };
    string maskPhoneNumber(const string& s){
        return PhoneNumber(s).redact();
    }
public:
    string maskPII(const string& s) {
        if(isEmail(s)){
            return maskEmail(s);
        }
        return maskPhoneNumber(s);
    }
};