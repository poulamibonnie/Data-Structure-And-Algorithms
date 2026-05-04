class Solution {
    unordered_map<char, string> dict{{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"}, {'9',"wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.empty()) {
            return {};
        }

        queue<string> q;
        q.push("");

        for (char digit : digits) {
            string code = dict[digit];
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                for (char ch : code) {
                    q.push(temp+ch);
                }
            }
        }

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};
