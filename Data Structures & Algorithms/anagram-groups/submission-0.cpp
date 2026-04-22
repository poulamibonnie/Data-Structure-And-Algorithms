class Solution {
public:
    string helper(string &str) {
        vector<int> freq(26, 0);
        string word = "";

        for ( char ch : str) {
            freq[ch - 'a']++;
        }

        for (auto it : freq) {
            word += to_string(it) +'%';
        }

        return word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> res;

        for (string str : strs) {
            dict[helper(str)].push_back(str);
        }

        for (auto it : dict) {
            res.push_back(it.second);
        }

        return res;
    }
};
