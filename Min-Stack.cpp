class MinStack {
public:
    void push(int x) {
       dataStack.push(x);
       if(minStack.empty()) {
           minStack.push(x);
       } else if (minStack.top() >= x){
           minStack.push(x);
       }
    }

    void pop() {
       if(dataStack.empty()) {
           return;
       }
       if(dataStack.top() == minStack.top()) {
           minStack.pop();
       }
       dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
    
private:
	stack<int> dataStack;
	stack<int> minStack;
};