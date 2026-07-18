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
        list<string> inWindow;
        for(int i = 0; i < words.front().size(); i++) {
            int windowStart = i;
            for(int j = 0; true;) {
                if(j == targetLength) {
                    res.push_back(windowStart);
                    frequency[inWindow.front()]++;
                    inWindow.erase(inWindow.begin());
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
                    for(list<string>::iterator itr = inWindow.begin(); itr != inWindow.end(); itr = inWindow.erase(itr)){
                        const string& s = *itr;
                        frequency[s]++;
                        windowStart += s.size();
                    }
                    j = 0;
                    windowStart += wordSize;
                }
                else if(itr->second > 0){
                    //cout<<"growing window"<<endl;
                    itr->second--;
                    inWindow.push_back(sub);
                    j++;
                } else {
                    //cout<<"inching window"<<endl;
                    if(inWindow.size() > 0) {
                        frequency[inWindow.front()]++;
                        inWindow.erase(inWindow.begin());
                        j--;
                        windowStart += wordSize;
                    }
                    
                }
                //cout<<"__________"<<endl;
            }

            for(list<string>::iterator itr = inWindow.begin(); itr != inWindow.end(); itr = inWindow.erase(itr)){
                const string& s = *itr;
                frequency[s]++;
            }
        }

        return res;
    }
};