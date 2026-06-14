class Trie {
public:

    Trie* child[26];
    bool isEnd;

    Trie() {
        isEnd = false;

        for(int i=0;i<26;i++)
            child[i] = NULL;
    }

    void insert(string word) {

        Trie* node = this;

        for(char c : word) {

            int idx = c - 'a';

            if(node->child[idx] == NULL)
                node->child[idx] = new Trie();

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {

        Trie* node = this;

        for(char c : word) {

            int idx = c - 'a';

            if(node->child[idx] == NULL)
                return false;

            node = node->child[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {

        Trie* node = this;

        for(char c : prefix) {

            int idx = c - 'a';

            if(node->child[idx] == NULL)
                return false;

            node = node->child[idx];
        }

        return true;
    }
};