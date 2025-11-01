class Vector2D {
    int r = 0;
    int c = 0;

    const vector<vector<int>>& vec;
    void crawl(){
        while(r < vec.size() && c >= vec[r].size()){
            c = 0;
            r++;
        }
    }
public:
    Vector2D(const vector<vector<int>>& vec) : vec(vec) {
        
    }
    
    int next() {
        crawl();
        int res = vec[r][c];
        c++;
        
        return res;
    }
    
    bool hasNext() {
        crawl();
        return r < vec.size() && c < vec[r].size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */