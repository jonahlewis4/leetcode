/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        vector<NestedInteger> v;
        bool counting = false;
        bool emptyPop = false;
        bool negative = false;
        for(const char c : s) {
            if(c == ' ') {
                continue;
            } else if(c == '['){
                //cout<<"pushing bracket"<<endl;
                counting = false;
                v.push_back(NestedInteger());
            } else if (c == ',') {
                counting = false;
                if(!emptyPop) {
                    //cout<<"popping comma"<<endl;
                    v[v.size() - 2].add(v.back());
                    negative = false;
                    v.pop_back();

                }
                emptyPop = false;

                
            } else if (c == ']'){
                counting = false;
                if(v.size() >= 2) {
                    //cout<<"popping bracket"<<endl;
                    v[v.size() - 2].add(v.back());
                    negative = false;
                    if(!v.back().isInteger() && v.back().getList().empty()) {
                        //cout<<"empty pop done"<<endl;
                        emptyPop = true;
                    }
                    v.pop_back();
                }

            } else if (c == '-'){
                negative = true;
            } else {
                if(!counting) {
                    counting = true;
                    //cout<<"pushing number"<<endl;
                    int digit = c - '0';
                    v.push_back(NestedInteger(digit * (negative ? -1 : 1)));
                } else {
                    //cout<<"updating number"<<endl;
                    if(negative) {
                        v.back().setInteger(v.back().getInteger() * 10 - (c - '0'));

                    } else {
                        v.back().setInteger(v.back().getInteger() * 10 + c - '0');
                    }
                }
            }
        }
        return v.front();
    }
};