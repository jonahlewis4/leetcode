class Solution {
    class Parser{
    public:
        bool virtual parse() = 0;
        string virtual name() const = 0;
    };
    class Parser4 : public Parser{
        const string& s;
        int i = 0;
    public:

        Parser4(const string& s) : s(s) {}

        bool skipSegment() {
            if(i >= s.size()) {
                return false;
            }
            int startI = i;
            int num = 0;
            if(!isdigit(s[i])) {
                return false;
            }
            num += s[i] - '0';
            i++;
            while(i < s.size() && s[i] != '.'){
                
                if(!isdigit(s[i])) {
                    return false;
                }
                
                num *= 10;
                num += s[i] - '0';
                if(num > 255) {
                    return false;
                }
                i++;
            }
            if(s[startI] == '0') {
                if(startI == i - 1 && num == 0) {  
                    return true;
                }
                return false;

            }
            return true;
        }

        bool skipDot() {
            if(i >= s.size()) {
                return false;
            }
            if(s[i] != '.') {
                return false;
            }
            i++;
            return true;
        }

        bool atEnd() {
            return i >= s.size();
        }

        bool parse() override {
            for(int i = 0; i < 3; i++) {
                if(!skipSegment()) {
                    return false;
                }
                if(!skipDot()) {
                    return false;
                }
            }
            if(!skipSegment()) {
                return false;
            }
            return atEnd();
        }

        string name() const override{
            return "IPv4";
        }
    };
    class Parser6 : public Parser {
        const string& s;
        int i = 0;
    public:
        Parser6(const string& s) : s(s) {}
        bool skipSegment() {
            if(i >= s.size()) {
                return false;
            }

            int startI = i;
            for(; i < startI + 4 && i < s.size() && s[i] != ':'; i++) {
                if(!isxdigit(s[i])) {
                    return false;
                }
            }

            return i > startI;
        }
        bool skipColon() {
            if(i >= s.size()) {
                return false;
            }
            if(s[i] != ':') {
                return false;
            }
            i++;
            return true;
        }
        bool atEnd() const{
            return i >= s.size();
        }
        bool parse() override {
            for(int i = 0; i < 7; i++) {
                if(!skipSegment()) {
                    return false;
                }
                if(!skipColon()) {
                    return false;
                }
            }

            if(!skipSegment()) {
                return false;
            }
            return atEnd();
        }
        string name() const override {
            return "IPv6";
        }
    };
    
public:
    string validIPAddress(const string& queryIP) {
        Parser4 p4 = Parser4(queryIP);
        Parser6 p6 = Parser6(queryIP);
        vector<Parser*> parsers = {
            &p4,
            &p6
        };
        for(Parser* p : parsers){
            if(p->parse()) {
                return p->name();
            }
        }
        return "Neither";
    }
};