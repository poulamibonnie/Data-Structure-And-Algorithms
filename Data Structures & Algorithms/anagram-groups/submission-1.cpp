class Solution {
public:
    string helper(string &str) {
        vector<int> freq(26,0);
        string word = "";

        for (char ch : str) {
            freq[ch - 'a']++;
        }

        for (int item : freq) {
            word += to_string(item) + '#';
        }

        return word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> store;
        vector<vector<string>> res;

        for (string str : strs) {
            store[helper(str)].push_back(str);
        }

        for (auto item : store) {
            res.push_back(item.second);
        }

        return res;
    }
};
