#include <iostream>
#include <sstream>

class Solution {
    string namedEntity = "&custSept";
public:

    string encode(vector<string>& strs) {
        string word = "";

        for (string str : strs) {
            word += str + '\n';
        }

        return word;
    }

    vector<string> decode(string s) {
        vector<string> res;
        stringstream ss(s);
        string word;
        while(std::getline(ss, word, '\n')) {
            res.push_back(word);
        }
        return res;
    }
};
