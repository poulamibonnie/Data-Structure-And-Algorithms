class Solution {
public:
    bool checkValidString(string s) {
        stack<int> store, dots;
        int idx = 0;;

        for (char ch : s) {
            if (ch == '*') {
                dots.push(idx);
            }
            else if (ch == '(') {
                store.push(idx);
            }
            else if (ch == ')') {
                if (store.empty() && dots.empty()) {
                    return false;
                }
                else if (!store.empty()) {
                    store.pop();
                }
                else if (!dots.empty()) {
                    dots.pop();
                }
                
            }
            idx++;
        }

        while(!dots.empty() && !store.empty()) {
            if (store.top() > dots.top()) return false;
            store.pop();
            dots.pop();
        }

        return store.empty();
    }
};
