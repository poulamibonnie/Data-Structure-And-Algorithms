class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> detector;

        int start = 0, end = 0, n = s.size(), mxLen = 0;


        while (end < n) {
            char ch = s[end];
            if (detector.count(ch)) {
                while (detector.count(ch)) {
                    detector.erase(s[start++]);
                }
            }
            detector.insert(ch);
            mxLen = max(mxLen, end - start + 1);
            end++;
        }

        return mxLen;
    }
};
