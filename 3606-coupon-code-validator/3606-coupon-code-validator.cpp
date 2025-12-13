class Solution {
    class Coupon {
        public:
            static unordered_map<string, int> _map;

            string code;
            string businessLine;
            bool isActive;

            bool isValid() const {
                return validCode() && validLine() && isActive;
            }

            bool validCode() const {
                if(code.size() == 0) {
                    return false;
                }
                for(const char c : code) {
                    if (!isalnum(c) && c != '_'){
                        return false;
                    }
                }
                return true;
            }

            bool validLine() const {
            

                if(_map.contains(businessLine)) {
                    return true;
                }

                return false;
            }

            bool operator< (const Coupon& other) const {
                int orderA = _map[businessLine];
                int orderB = _map[other.businessLine];
                
                if(orderA < orderB) {
                    return true;
                } else if (orderA > orderB) {
                    return false;
                } else {
                    return code < other.code;
                }
            }
        };
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    


        vector<Coupon> coupons;
        for(int i = 0; i < code.size(); i++) {
            Coupon c;
            c.code = code[i];
            c.businessLine = businessLine[i];
            c.isActive = isActive[i];
        
            if(c.isValid()) {
                coupons.push_back(c);
            }
        }

        sort(coupons.begin(), coupons.end());

        vector<string> res(coupons.size());
        for(int i = 0; i < res.size(); i++) {
            res[i] = coupons[i].code;
        }

        return res;
    }
};
unordered_map<string, int> Solution::Coupon::_map = {
                {"electronics", 0},
                {"grocery", 1},
                {"pharmacy", 2},
                {"restaurant", 3}
            };