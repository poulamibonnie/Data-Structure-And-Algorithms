class Solution {
public:
    string helper(string &s) {
        vector<int> freq(26, 0);
        string word = "";

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int item : freq) {
            word += to_string(item) + '#';
        }
        return word;
    }
    bool isAnagram(string s, string t) {
        s = helper(s);
        t = helper(t);
        return s == t;
    }
};
