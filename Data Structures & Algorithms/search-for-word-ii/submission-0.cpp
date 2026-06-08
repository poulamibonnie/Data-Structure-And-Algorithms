class TrieNode {
    public:
        char currLetter;
        unordered_map<char, TrieNode*> address;
        bool isEnd;
        TrieNode(){
            isEnd = false;
        }
};
class Solution {
    TrieNode * root = new TrieNode();
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    void addWord(string &word) {
        TrieNode * currNode = this->root;
        for (char ch : word) {
            if (currNode->address.count(ch)) {
                currNode = currNode->address[ch];
            }
            else {
                TrieNode * newNode = new TrieNode();
                newNode->currLetter = ch;
                currNode->address[ch] = newNode;
                currNode = currNode->address[ch];
            }
        }
        currNode->isEnd = true;
    }

    void helper(vector<vector<char>>& board, int r, int c, TrieNode * currNode, string word, vector<string> &res) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }
        else if (!currNode->address.count(board[r][c])) {
            return;
        }
        char letter = board[r][c];
        board[r][c] = '&';
        word += letter;
        currNode = currNode->address[letter];
        if (currNode->isEnd) {
            res.push_back(word);
            currNode->isEnd = false;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            helper(board, nr, nc, currNode, word, res);
        }
        board[r][c] = letter;
        word.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string word : words) {
            addWord(word);
        }

        vector<string> res;
       
        int R = board.size(), C = board[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                helper(board, i, j, this->root, "", res);
            }
        }

        return res;
    }
};
