class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories = split(path, '/');
        if(path.size() == 0){
            return "/";
        }
        vector<string> res;

        for(const string & s : directories){
            if(s == ".."){
                if(!res.empty()){
                    res.pop_back();
                }
            } else if (s == "."){
                continue;
            } else {
                res.push_back(s);
            }
        }

        string joined = join(res, '/');
        return "/" + joined;

        
    }
    vector<string> split(const string& s, const char delim){
        int l = 1;
        int r = 1;
        vector<string> ans;
        while(r < s.size()){
            if(s[r] == delim){
                string substr = s.substr(l, r - l);
                if(substr != ""){
                    ans.push_back(substr);
                }

                l = r + 1;               
            }
            r++;
        }
        string substr = s.substr(l, r - l);
        if(substr != ""){
            ans.push_back(substr);
        }
        return ans;
    }
    string join(const vector<string> & strings, const char delim){
        string res = "";
        for(const string s : strings){
            res += s;
            res.push_back(delim);
        }
        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
};