class Solution {
vector<vector<int>> res;
int k;
int n;
unordered_set<int> allowed;
vector<int> cur;
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        for(int i = 1; i <= n; i++){
            allowed.insert(i);
        }
        dfs()  ;
        return res;
    }
    void dfs() {
        auto _cur = &cur;
        auto _allowed = &allowed;
        auto _res = &res;
        
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        
        if(cur.size() + allowed.size() < k){
            return;
        }
        
        //use the current one.
        auto begin = allowed.begin();

        //recurse with the number in the combination and not allowed.
        //find all combinations that include that number.
        cur.push_back(*begin);
        int num = *begin;
        allowed.erase(begin);
        dfs();

        //recurse with the numnber not in the combination and not allowed.
        //(find all combinations that do not include that number) 
        cur.pop_back();
        dfs();


        
        allowed.insert(num);
    }
};