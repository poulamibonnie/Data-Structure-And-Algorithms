class Solution {
    bool isPalindrome(string &s) {
        int i = 0, j = s.size() - 1;

        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void helper(string &s, vector<string> &temp, vector<vector<string>> &res) {
        if (s.empty()) {
            res.push_back(temp);
            return;
        }
        int start = 0;
        for (int end = 0; end < s.size(); end++) {
            string left = s.substr(0, end - start + 1);
            string ros = s.substr(end + 1);
            if (isPalindrome(left)) {
                temp.push_back(left);
                helper(ros, temp, res);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        helper(s, temp, res);
        return res;
    }
};
