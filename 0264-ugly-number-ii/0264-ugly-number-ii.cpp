class Solution {
public:
    int nthUglyNumber(int n) {
        struct Number {
            long long total = 0;
            bool operator<(const Number& other) const{
                return total > other.total;
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

        priority_queue<Number> pq;
        unordered_set<int> enqueued;
        pq.push({1});
       
        for(int i = 1; i < n; i++){
            Number top = pq.top();
            pq.pop();
            
            Number nextTwo = top.nextTwo();
            Number nextThree = top.nextThree();
            Number nextFive = top.nextFive();

            if(!enqueued.contains(nextTwo.total)){
                pq.push(nextTwo);
            }

            if(!enqueued.contains(nextThree.total)){
                pq.push(nextThree);
            }

            if(!enqueued.contains(nextFive.total)){
                pq.push(nextFive);
            }


            enqueued.insert(nextTwo.total);
            enqueued.insert(nextThree.total);
            enqueued.insert(nextFive.total);
        }

        return pq.top().total;
    }
};