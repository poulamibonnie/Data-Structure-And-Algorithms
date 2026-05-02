class Solution {
public:
    void helper(int op, int cp, string s, vector<string> &res) {
        if (cp == 0 && op == 0) {
            cout<<s<<endl;
            res.push_back(s);
            return;
        }
        if (op > 0) {
            helper(op - 1, cp, s + "(", res);
        }
        if (op > 0 && op < cp) {
           helper(op, cp - 1, s + ')', res);
        }
        if (op == 0 && op < cp) {
            helper(op, cp - 1, s + ')', res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        helper(n, n, s, res);
        return res;
    }
};
