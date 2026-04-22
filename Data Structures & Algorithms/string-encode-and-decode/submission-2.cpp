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
        int i = 0, j = 0;
        while(i < s.size()){
            string size_str = "";
            
            while(s[i] != '#') {
                size_str += s[i++];
            }
            //cout<<size_str<<endl;
            int start = i + 1;
            int length = stoi(size_str);
            res.push_back(s.substr(start, length));
            i +=  length + 1;
            
        }
        return res;
    }
};
