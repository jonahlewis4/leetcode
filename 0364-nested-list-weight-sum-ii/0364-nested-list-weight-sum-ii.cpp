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
private:
    int maxDepth = 0;
    int sum = 0;
    void maxDepthHelper(const vector<NestedInteger> &nestedList, int depth){
        maxDepth = max(maxDepth, depth);
        for(const NestedInteger &nested : nestedList){
            if(!nested.isInteger()){ //if it is a list
                maxDepthHelper(nested.getList(), depth + 1);
            }
        }
        
    }
    void sumHelper(const vector<NestedInteger> &nestedList, int depth){
        for(const NestedInteger &nested : nestedList){
            if(nested.isInteger()){
                sum += weightProduct(nested.getInteger(), depth, maxDepth);
            } else {
                sumHelper(nested.getList(), depth + 1);
            }
        }
    }
    inline int weightProduct(int num, int depth, int maxDepth){
        return (maxDepth - depth + 1) * num; 
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int total = 0;
        maxDepthHelper(nestedList, 1);
        sumHelper(nestedList, 1);
        return sum;
        
    }
};