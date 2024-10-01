# Min Stack

## Brute Force
```cpp
class MinStack {
private:
    stack<int> s1, s2;

public:
    MinStack() {}

    void push(int val) {
        s1.push(val);
        if(s2.empty()||val<=s2.top()){
            s2.push(val);
        }
    }
    void pop(){
    
        if(!s2.empty()&&s2.top()==s1.top()){
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```


## Optimized
```cpp
class MinStack {
private:
    vector<int> stack;
    int min;
public:
    MinStack() {min = INT_MAX;}

    void push(int val) {
        if (stack.empty()||min >=val) {
            // Push the current minimum also to the stack as it will help us to
            // see the previous minimum element if the current minimum is
            // removed
            stack.push_back(min);
            min = val;
        }
        stack.push_back(val); // Push the actual element to the stack
    }

    void pop() {
        if (min == stack.back()) {
            stack.pop_back();//removing original value
            min = stack.back();// changing the current min to previous min
            stack.pop_back();// removing the previous min
        } else {
            stack.pop_back();// removing the element
        }
    }

    int top() { return stack.back(); }

    int getMin() { return min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```