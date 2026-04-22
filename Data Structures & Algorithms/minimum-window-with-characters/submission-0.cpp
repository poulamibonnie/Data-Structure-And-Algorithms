class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> source, target;
        
        for (char ch : t) {
           target[ch]++; 
        }
        int reqd = target.size();

        int start = 0, end = 0;
        int ans[3] = {0, 0, -1};
        int n = s.size();
        int formed = 0;

        while (end < n) {
            char ch = s[end];
            source[ch]++;
            if (target.count(ch) && target[ch] == source[ch]) {
                formed++;
                while (reqd == formed) {
                    char nch = s[start];
                    if (source.count(ch)) {
                        source[nch]--;
                        if (source[nch] < target[nch]) {
                            formed--;
                            if (ans[2] == -1 || ans[2] > (end - start + 1)) {
                                ans[0] = start;
                                ans[1] =  end;
                                ans[2] = end - start + 1;
                            }
                        }
                    } 
                    start++;
                }

            }

            end++;
        }

        return (ans[2] == -1) ? "" : s.substr(ans[0], ans[2]);
    }
};
