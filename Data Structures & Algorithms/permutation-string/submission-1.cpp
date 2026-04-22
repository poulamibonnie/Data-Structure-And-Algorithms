class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> source(26, 0);
        vector<int> target(26, 0);

        if (s1.size() > s2.size()) {
            return false;
        }

        for (char ch : s1) {
            source[ch - 'a']++;
        }

        int end = 0, start = 0, windowSize = s1.size();

        while (end < windowSize) {
            char ch = s2[end];
            target[ch - 'a']++;
            end++;
        }

        while (end < s2.size()) {
            if (source == target) {
                return true;
            }
            char remElm = s2[start];
            target[remElm - 'a']--;
            start++;
            char newElm = s2[end];
            target[newElm - 'a']++;
            end++;
        }

        return source == target;
    }
};
