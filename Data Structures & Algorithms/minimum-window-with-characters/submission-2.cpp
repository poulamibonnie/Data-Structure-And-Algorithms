class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> source, target;
        int found = 0, required = 0;
        for (char ch : t) {
            source[ch]++;
        }
        required = source.size();

        int start = 0, end = 0, n = s.size();
        int ans[3] = {-1, start, end};

        while (end < n) {
            char ch = s[end];
            target[ch]++;
            if (target[ch] == source[ch]) {
                found++;
                if (found == required) {
                    while(found == required) {
                        if (ans[0] == -1 || end - start + 1 < ans[0] ) {
                            ans[0] = end - start + 1;
                            ans[1] = start;
                            ans[2] = end;
                        }
                        char nch = s[start++];
                        target[nch]--;
                        if (source.count(nch) && target[nch] < source[nch]) {
                            found--;
                        }
                    }
                    
                }
            }
            end++;
        }

        return (ans[0] == -1) ? "" : s.substr(ans[1], ans[0]);
    }
};
