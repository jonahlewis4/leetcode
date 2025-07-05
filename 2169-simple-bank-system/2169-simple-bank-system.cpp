class Bank {
    vector<long long>& balance;
    int n;
    bool inRange(int account) const {
        return 1 <= account && account <= n;
    }
public:
    Bank(vector<long long>& balance) : balance(balance){
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!inRange(account1) || !inRange(account2)){
            return false;
        }
        account1--;
        account2--;
        if(money <= balance[account1]) {
            balance[account1] -= money;
            balance[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(!inRange(account)) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!inRange(account)) {
            return false;
        }
        account--;
        if(money <= balance[account]) {
            balance[account] -= money;
            return true;
        }
        return false;
    }

};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */