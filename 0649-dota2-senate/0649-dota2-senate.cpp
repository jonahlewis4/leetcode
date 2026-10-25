class Solution {
    class Senate;
    class Party{
    protected:
        Party* op;
        queue<int> q;
        friend class Senate;
        int n;
        Party(Party* op, const string& s, char c):op(op){
            n = s.size();
            for(int i = 0; i < s.size(); i++){
                if(c == s[i]){
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
        string virtual announce() = 0;
    };
    class Radiant : public Party{
    public:
        Radiant(Party* op, const string& s) : Party(op, s, 'R') {}
        string announce() override {
            return "Radiant";
        }

    };
    class Dire : public Party{
    public:
        Dire(Party* op, const string& s) : Party(op, s, 'D') {}
        string announce() override {
            return "Dire";
        }
    };
    class Senate{
        Radiant radiant;
        Dire dire;
        const string& s;

        string handle() {
            Party* curParty = min(static_cast<Party*>(&dire), static_cast<Party*>(&radiant), [](const Party* const a, const Party* const b){
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
        Senate(const string& s): s(s),  dire(&radiant, s), radiant(&dire, s){}
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