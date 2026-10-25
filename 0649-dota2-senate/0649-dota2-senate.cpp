class Solution {
    class Senate;
    class Party{
        Party* op;
        string name;
        queue<int> q;
        friend class Senate;
        int n;
        Party(Party* op, string name, const string& s):op(op), name(name){
            n = s.size();
            for(int i = 0; i < s.size(); i++){
                if(name.front() == s[i]){
                    q.push(i);
                }
            }
        };
    public:
        void act(){
            op->q.pop();
            q.push(q.front() + n);
            q.pop();
        }
        string announce(){
            return name;
        }
    };
    class Senate{
        Party radiant;
        Party dire;
        const string& s;

        string handle() {
            Party* curParty = min(&dire, &radiant, [](const Party* const a, const Party* const b){
                if(a->q.empty()){
                    return false;
                }
                if(b->q.empty()){
                    return true;
                }

                return a->q.front() < b->q.front();
            });
            if(curParty->op->q.empty()) {
                return curParty->announce();
            }

            curParty->act();
            return "";
        }
    public:
        Senate(const string& s): s(s),  dire(&radiant, "Dire", s), radiant(&dire, "Radiant", s){}
        string getWinner(){
            while(true) {
                string x = handle();
                if(!x.empty()) {
                    return x;
                }
            }
        }

    };
    
    
public:
    string predictPartyVictory(string senate) {
        Senate s(senate);
        return s.getWinner();
    }
};