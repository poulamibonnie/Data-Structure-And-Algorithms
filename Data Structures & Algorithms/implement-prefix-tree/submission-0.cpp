class TrieNode {
    public:
        char currLetter;
        unordered_map<char, TrieNode * > address;
        bool isEnd;
        TrieNode() {
            isEnd = false;
        }
};
class PrefixTree {
    TrieNode * root = new TrieNode();
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TrieNode * currNode = this->root;

        for (char ch : word) {
            if (currNode->address.count(ch)) {
                currNode = currNode->address[ch];
            }
            else {
                TrieNode * newNode = new TrieNode();
                newNode->currLetter = ch;
                currNode->address[ch] = newNode;
                currNode = newNode;
            }
        }
        currNode->isEnd = true;

    }
    
    bool search(string word) {
        TrieNode * currNode = this->root;
        for (char ch : word) {
            if (currNode->address.count(ch)) {
                currNode = currNode->address[ch];
            }
            else {
                return false;
            }
        }
        return currNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode * currNode = this->root;
        for (char ch : prefix) {
            if (currNode->address.count(ch)) {
                currNode = currNode->address[ch];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
