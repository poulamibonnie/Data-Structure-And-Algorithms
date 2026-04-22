class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> store;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '{' || ch == '[' || ch == '(') {
                store.push(ch);
            }
            else {
                if (store.empty()) {
                    return false;
                }
                else if (store.top() == '(' && ch == ')') {
                    store.pop();
                }
                else if (store.top() == '[' && ch == ']') {
                    store.pop();
                }
                else if (store.top() == '{' && ch == '}') {
                    store.pop();
                }
                else {
                    store.push(ch);
                }
            }
        }
        return store.empty();
    }
};
