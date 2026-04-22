class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;

        for (string ch : tokens) {
            
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int b = store.top();
                store.pop();
                int a = store.top();
                store.pop();

                if (ch == "+") {
                    store.push(a + b);
                }
                else if (ch == "-") {
                    store.push(a - b);
                }
                else if (ch == "*") {
                    store.push(a * b);
                }
                else {
                    store.push(a / b);
                }
            }
            else {
                store.push(stoi(ch));
            }
             
        }

        int res = 0;

        while (!store.empty()) {
            res += store.top();
            store.pop();
        }

        return res;
    }
};
