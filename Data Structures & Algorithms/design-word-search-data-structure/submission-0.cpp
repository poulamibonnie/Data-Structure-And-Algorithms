class TrieNode {
    public:
        char currLetter;
        unordered_map<char, TrieNode *> address;
        bool isEnd;

        TrieNode() {
            isEnd = false;
        }
};
class WordDictionary {
    TrieNode * root = new TrieNode();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode * currNode = this->root;

        for (char ch : word) {
            if (!currNode->address.count(ch)) {
                TrieNode * newNode = new TrieNode();
                newNode->currLetter = ch;
                currNode->address[ch] = newNode;
            }
            currNode = currNode->address[ch];
        }
        currNode->isEnd = true;
    }
    
    bool search(string word) {
        return helper(word, this->root);
    }

    bool helper(string &word, TrieNode* currNode) {
        int n = word.size();

        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (currNode->address.count(ch)) {
                currNode = currNode->address[ch];
            }
            else if (ch == '.') {
                string ros = word.substr(i + 1);
                for (auto add : currNode->address) {
                    if (helper(ros, add.second)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                return false;
            }
        }
        return currNode->isEnd;
    }
};
