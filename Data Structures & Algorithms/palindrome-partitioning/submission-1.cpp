class Solution {
    bool isValid(string &str) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        return rev == str;
    }
public:
    void helper(string &str, vector<string> &temp, vector<vector<string>> &res) {
        if (str.empty()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < str.size(); i++) {
            string currWord = str.substr(0, i + 1);
            string ros = str.substr(i+1);
            if (isValid(currWord)) {
                temp.push_back(currWord);
                helper(ros, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        helper(s, temp, res);
        return res;
    }
};
