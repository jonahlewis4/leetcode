class Solution {
public:
    int compareVersion(const string& version1, const string& version2) {
        int lastDot1 = -1;
        int lastDot2 = -1;
        while(true) {
            if(lastDot1 == version1.size() && lastDot2 == version2.size()) {
                return 0;
            }

            int nextDot1 = version1.find('.', lastDot1 + 1);
            if(nextDot1 == string::npos){
                nextDot1 = version1.size();
            }
            int nextDot2 = version2.find('.', lastDot2 + 1);
            if(nextDot2 == string::npos) {
                nextDot2 = version2.size();
            }

            string sub1 = lastDot1 == version1.size() ? "" : version1.substr(lastDot1 + 1, nextDot1 - lastDot1 - 1);
            string sub2 = lastDot2 == version2.size() ? "" : version2.substr(lastDot2 + 1, nextDot2 - lastDot2 - 1);

            int n1 = sub1 == "" ? 0 : stoi(sub1);
            int n2 = sub2 == "" ? 0 : stoi(sub2);

            if(n1 < n2) {
                return -1;
            } 
            if(n1 > n2) {
                return 1;
            }

            lastDot1 = nextDot1;
            lastDot2 = nextDot2;

        }
    }
};