class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int dels = 0;
        for(int i = 0; i < strs.front().size(); i++) {
            bool clear = true;

            for(int j = 1; j < strs.size(); j++) {
                const string prev = strs[j - 1].substr(0, i + 1);
                const string cur = strs[j].substr(0, i + 1);

                if(cur < prev) {
                    clear = false;
                    break;
                }
            }

            if(!clear) {
                for(auto & str : strs) {
                    str[i] = '_';
                }
                dels++;
            }
        }

        return dels;
    }
};