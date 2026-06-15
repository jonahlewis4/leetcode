class Solution {
    class Parser{
    const string& s;
    int i = 0;
    public:
        Parser(const string& s) : s(s) {

        }

        bool fillNextNode(int*& out) {
            if(i >= s.size()) {
                return false;
            }
            if(s[i] == '#') {
                out = nullptr;
                i+=2;
                return true;
            }
            *out = 0;
            while(i < s.size() && s[i] != ',') {
                char c = s[i] - '0';
                *out *= 10;
                *out += c;
                i++;
            }
            i++;
            return true;
        }
    };

    static bool r(Parser& p) {
        int nextNode;
        int* nextNodePtr = &nextNode;
        bool valid = p.fillNextNode(nextNodePtr);
        if(!valid) {
            return false;
        }
        if(!nextNodePtr) {
            return true;
        }
        bool left = r(p);
        if(!left) {
            return false;
        }
        bool right = r(p);
        if(!right) {
            return false;
        }

        return true;
    }
public:
    bool isValidSerialization(const string& preorder) {
        Parser p(preorder);
        bool valid = r(p);
        if(!valid) {
            return false;
        }
        int x;
        int* rando = &x;
        return !p.fillNextNode(rando);
    }
};