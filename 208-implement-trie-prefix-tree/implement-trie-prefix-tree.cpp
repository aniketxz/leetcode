class Trie {
public:

    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* ptr = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(ptr->children[idx] == NULL) {
                trieNode* newNode = getNode();
                ptr->children[idx] = newNode;
            }

            ptr = ptr->children[idx];
        }
        
        ptr->isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* ptr = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(ptr->children[idx] == NULL)
                return false;

            ptr = ptr->children[idx];
        }

        return ptr != NULL && ptr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        trieNode* ptr = root;

        for(char ch : prefix) {
            int idx = ch - 'a';

            if(ptr->children[idx] == NULL)
                return false;

            ptr = ptr->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */