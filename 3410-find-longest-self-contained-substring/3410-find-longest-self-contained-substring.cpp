class Solution {
public:
    int maxSubstringLength(string s) {
        int n = s.size();
        unordered_map<char, int> first;
        unordered_map<char, int> last;

        for(int i = 0; i < n; i++){
            if(first.find(s[i]) == first.end()){
                first[s[i]] = i;
            }
            last[s[i]] = i;
        }

        int maxLen = -1;
        for(const auto p : first){
            int firstIndex = p.second;
            int lastIndex = last[p.first];

            for(int i = firstIndex; i < n; i++){
                lastIndex = max(lastIndex, last[s[i]]);
                if(first[s[i]] < firstIndex){
                    break;
                } else {
                    if(i - firstIndex + 1 < n && i == lastIndex){
                        maxLen = max(i - firstIndex + 1, maxLen);
                    }
                }
            }
        }
        return maxLen;


    }
};