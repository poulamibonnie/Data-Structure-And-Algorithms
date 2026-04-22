class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int maxF = 0, start = 0, end = 0, n = s.size(), mxLen = 0;

        while (end < n) {
            char ch = s[end];
            freq[ch - 'A']++;
            maxF = max(maxF, freq[ch - 'A']);

            while ((end - start + 1) - maxF > k) {
                char nch = s[start];
                freq[nch - 'A']--;
                start++;
            }
            mxLen = max(mxLen, end - start + 1);
            end++;
        }

        return mxLen;
    }
};
