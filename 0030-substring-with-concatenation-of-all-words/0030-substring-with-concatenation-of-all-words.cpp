class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        using map = unordered_map<string, int>;
        map word2Id;
        for(const string& s : words) {
            map::iterator itr = word2Id.find(s);
            if(itr == word2Id.end()) {
                word2Id[s] = word2Id.size();
            }
        }
        vector<int> frequency(word2Id.size());
        for(const string& s : words) {
            int id = word2Id[s];
            frequency[id]++;
        }

        vector<int> sIds(s.size(), -1);
        int wordSize = words.front().size();

        for(int i = 0; i < s.size(); i++) {
            string s2 = s.substr(i, wordSize);
            map::iterator itr = word2Id.find(s2);
            if(itr == word2Id.end()) {
                continue;
            }
            sIds[i] = itr->second;
        }

        vector<int> res;
        int targetLength = words.size();
        for(int i = 0; i < words.front().size(); i++) {
            int windowStart = i;
            int j = 0;
            while(true) {
                if(j == targetLength) {
                    res.push_back(windowStart);
                    int first = sIds[windowStart];
                    frequency[first]++;
                    j--;
                    windowStart += wordSize;
                }
                int newWordIndex = windowStart + j * wordSize;
                if(newWordIndex + wordSize > s.size()){
                    break;
                }
                int id = sIds[newWordIndex];
                //cout<<"sub: "<<sub<<endl;
                if(id == -1) {
                    //cout<<"clearing list"<<endl;
                    while(j > 0){
                        int s2 = sIds[windowStart];
                        frequency[s2]++;
                        windowStart += wordSize;
                        j--;
                    }
                    windowStart += wordSize;
                } else if(frequency[id] > 0){
                    //cout<<"growing window"<<endl;
                    frequency[id]--;
                    j++;
                } else {
                    //cout<<"inching window"<<endl;

                    frequency[sIds[windowStart]]++;
                    j--;
                    windowStart += wordSize;
                    
                }
                //cout<<"__________"<<endl;
            }

            while(j > 0){
                int s2 = sIds[windowStart];
                frequency[s2]++;
                j--;
                windowStart += wordSize;
            }
        }

        return res;
    }
};