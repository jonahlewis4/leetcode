/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    int cachedNext;
    bool cached = false;

    int i = 0;

    const vector<NestedInteger>& list;
    
    NestedIterator* itr = nullptr;

    void calcNext() {

        if(i >= list.size()) {
            cached = false;
            return;
        }


        //nested iterator case!
        while(i < list.size()) {
            if(list[i].isInteger()) {
                int result = list[i].getInteger();
            
                i++;
                cachedNext = result;
                cached = true;
                return;
            }

            if(!itr) {
                itr = new NestedIterator(list[i].getList());
            }
            if(itr->hasNext()) {
                cached = true;
                cachedNext = itr->next();
                return;
            } else {
                i++;
                delete itr;
                itr = nullptr;
            }
        }
        cached = false;

    }
public:
    NestedIterator(const vector<NestedInteger> &nestedList) : list(nestedList) {
        
    }
    
    
    
    int next() {
        //technically we don't need this if hasNext is always called before next, but just to be safe.
        if(!cached) {
            calcNext();
        }
        cached = false;

        return cachedNext;
    }
    
    bool hasNext() {
        if(cached) {
            return true;
        }

        calcNext();
        return cached;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */