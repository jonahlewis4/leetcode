class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        unordered_set<string> seen;
        
        for (const string& f : folder) {
            // Check if a valid parent folder exists
            size_t pos = 0;
            bool isSub = false;
            while ((pos = f.find('/', pos + 1)) != string::npos) {
                if (seen.count(f.substr(0, pos))) {
                    isSub = true;
                    break;
                }
            }
            if (!isSub) {
                res.push_back(f);
                seen.insert(f);
            }
        }
        
        return res;
    }
};
