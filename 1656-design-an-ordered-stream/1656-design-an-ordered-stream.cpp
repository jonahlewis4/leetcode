class OrderedStream {
    vector<string> s;
    int i = 1;
public:
    OrderedStream(int n) {
        s.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        s[idKey] = value;
        vector<string> res;
        while(i < s.size() && s[i] != "") {
            res.push_back(s[i]);
            i++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */