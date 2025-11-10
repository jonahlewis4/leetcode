class Solution {
public:
    int nthUglyNumber(int n) {
        struct Number {
            long long total = 0;
            bool operator<(const Number& other) const{
                return total < other.total;
            }

            Number nextTwo() const {
                return Number{
                    .total = total * 2
                };
            }

            Number nextThree() const {
                return Number {
                    .total = total * 3
                };
            }
            Number nextFive() const {
                return Number {
                    .total = total * 5
                };
            }
        };

        set<Number> pq;
        pq.insert({.total = 1});
       
        for(int i = 1; i < n; i++){
            Number top = *pq.begin();
            pq.erase(pq.begin());
            
            Number nextTwo = top.nextTwo();
            Number nextThree = top.nextThree();
            Number nextFive = top.nextFive();



            pq.insert(nextTwo);
            pq.insert(nextThree);
            pq.insert(nextFive);
        }

        return (*pq.begin()).total;
    }
};