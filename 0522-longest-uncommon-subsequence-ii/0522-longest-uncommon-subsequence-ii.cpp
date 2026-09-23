class Solution {
    static bool isSub(const string& small, const string& large) {
        int smallI = 0;
        int largeI = 0;

        while(largeI < large.size()){
            if(large[largeI] == small[smallI]) {
                smallI++;
            }
            if(smallI >= small.size()){
                return true;
            }
            largeI++;
        }

        return false;
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string&a, const string&b){return a.size() > b.size();});
        for(int i = 0; i < strs.size(); i++) {
            bool works = true;
            for(int j = 0; j < strs.size() && strs[j].size() >= strs[i].size(); j++) {
                if(i==j){
                    continue;
                }
                if(isSub(strs[i], strs[j])) {
                    works = false;
                    break;
                }
            }
            if(works) {
                return strs[i].size();
            }
        }
        return -1;
    }
};