class MinStack {
    stack<pair<int,int>> store;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (store.empty()) {
            store.push({val, val});
            return;
        }
        int currMin = store.top().second;
        store.push({val, min(val, currMin)});
    }
    
    void pop() {
        store.pop();
    }
    
    int top() {
        return store.top().first;
    }
    
    int getMin() {
        return store.top().second;
    }
};
