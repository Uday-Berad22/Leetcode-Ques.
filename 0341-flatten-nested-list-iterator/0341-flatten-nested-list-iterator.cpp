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
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1;i>=0;i--){
            stk.push(nestedList[i]);
        }
    }
    
    int next() {
        if(hasNext()){
            int x=stk.top().getInteger();
            stk.pop();
            return x;
        }
        return -1;
    }
    
    bool hasNext() {
        while(!stk.empty()){
            if(stk.top().isInteger()){
                return true;
            }
            vector<NestedInteger> newList=stk.top().getList();
            stk.pop();
            for(int i=newList.size()-1;i>=0;i--){
                stk.push(newList[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */