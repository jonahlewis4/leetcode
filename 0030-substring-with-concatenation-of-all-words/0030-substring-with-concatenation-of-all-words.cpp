class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        using map = unordered_map<string, int>;
        map frequency;
        for(const string& s : words) {
            frequency[s]++;
        }

        vector<int> res;
        int targetLength = words.size();
        int wordSize = words.front().size();
        for(int i = 0; i < words.front().size(); i++) {
            int windowStart = i;
            int j = 0;
            while(true) {
                if(j == targetLength) {
                    res.push_back(windowStart);
                    string first = s.substr(windowStart, wordSize);
                    frequency[first]++;
                    j--;
                    windowStart += wordSize;
                }
                int newWordIndex = windowStart + j * wordSize;
                if(newWordIndex + wordSize > s.size()){
                    break;
                }
                string sub = s.substr(newWordIndex, wordSize);
                map::iterator itr = frequency.find(sub);
                //cout<<"sub: "<<sub<<endl;
                if(itr == frequency.end()) {
                    //cout<<"clearing list"<<endl;
                    while(j > 0){
                        const string& s2 = s.substr(windowStart, wordSize);
                        frequency[s2]++;
                        windowStart += s2.size();
                        j--;
                    }
                    windowStart += wordSize;
                } else if(itr->second > 0){
                    //cout<<"growing window"<<endl;
                    itr->second--;
                    j++;
                } else {
                    //cout<<"inching window"<<endl;

                    frequency[s.substr(windowStart, wordSize)]++;
                    j--;
                    windowStart += wordSize;
                    
                }
                //cout<<"__________"<<endl;
            }

            while(j > 0){
                const string& s2 = s.substr(windowStart, wordSize);
                frequency[s2]++;
                j--;
            }
        }

        return res;
    }
};