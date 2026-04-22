class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int maxFreq = 0, start = 0, end = 0, res = 0;

        while (end < n) {
            char ch = s[end];
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);

            while ( (end - start + 1) - maxFreq > k) {
                freq[s[start++]]--;
            }
            res = max(res, end - start + 1);
            end++;
        }   

        return res;

    }
};
