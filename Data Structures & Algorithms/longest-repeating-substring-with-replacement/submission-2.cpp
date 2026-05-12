class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int start = 0, end = 0, res = 0;
        for (int end = 0; end < s.size(); end++) {
            freq[s[end]]++;
            maxFreq = max(maxFreq, freq[s[end]]);

            while ((end - start + 1) - maxFreq > k) {
                freq[s[start]]--;
                start++;
            }
            res = max(res, (end - start + 1));
        }

        return res;
    }
};
