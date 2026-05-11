class Solution {
public:
    bool isValid(string &nextWord, string &currWord) {
        int cnt = 0;

        if (nextWord.size() != currWord.size()) {
            return false;
        }

        int i = 0;
        while (i < currWord.size()) {
            if (currWord[i] != nextWord[i]) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
            }
            i++;
        }

        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict;
        // Insert word to dict for eay access
        for (string word : wordList) {
            wordDict.insert(word);
        }

        queue<string> q;
        q.push(beginWord);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            step++;
            for (int i = 0; i < size; i++) {
                auto currWord = q.front();
                q.pop();
                if (currWord == endWord) {
                    return step;
                }
                // Remove as already visited
                wordDict.erase(currWord);

                for (string nextWord : wordDict) {
                    if (isValid(nextWord, currWord)) {
                        
                        q.push(nextWord);
                    }
                }
            }
        }
        return 0;
    }
};
