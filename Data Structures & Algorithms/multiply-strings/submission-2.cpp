class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += mul;
                res[i + j + 1] += res[i + j]/10;
                res[i + j] = res[i + j] %10;
            }
        }

        reverse(res.begin(), res.end());

        string ans = "";
        bool lz = true;
        int i = 0;
        while ( i < res.size()) {
            while (lz && res[i] == 0) {
                i++;
            }
            lz = false;
            ans += to_string(res[i]);
            i++;
        }
        return ans;
    }
};
