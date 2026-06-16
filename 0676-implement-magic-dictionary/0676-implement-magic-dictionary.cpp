class Trie {
public:
    Trie* child[26] = {};
    bool isEnd;

    Trie() {
        isEnd = false;
    }

    void insert(string word) {

        Trie* node = this;

        for(char c : word) {

            int idx = c - 'a';

            if(node->child[idx] == NULL) {
                node->child[idx] = new Trie();
            }

            node = node->child[idx];
        }

        node->isEnd = true;
    }
};

class MagicDictionary {
public:

    Trie* root;

    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {

        for(string word : dictionary) {
            root->insert(word);
        }
    }

    bool dfs(string &word,
             int pos,
             Trie* node,
             bool modified) {

        if(pos == word.size()) {
            return node->isEnd && modified;
        }

        int idx = word[pos] - 'a';

        // Use same character
        if(node->child[idx]) {

            if(dfs(word,
                   pos + 1,
                   node->child[idx],
                   modified))
                return true;
        }

        // Use one modification
        if(!modified) {

            for(int i = 0; i < 26; i++) {

                if(i == idx)
                    continue;

                if(node->child[i]) {

                    if(dfs(word,
                           pos + 1,
                           node->child[i],
                           true))
                        return true;
                }
            }
        }

        return false;
    }

    bool search(string searchWord) {

        return dfs(searchWord,
                   0,
                   root,
                   false);
    }
};