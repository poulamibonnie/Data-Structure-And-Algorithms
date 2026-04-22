#include <iostream>
#include <sstream>

class Solution {
    
public:

    string encode(vector<string>& strs) {
        string word = "";

        for (string str : strs) {
            word += to_string(str.size()) + '#' + str;
        }

        return word;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int start = j + 1;
            int end = stoi(s.substr(i, j - i));
            res.push_back(s.substr(start, end ));
            i = j + end + 1;

        }
        return res;
    }
};
