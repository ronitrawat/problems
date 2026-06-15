class Trie{
public:
    Trie* child[26] = {};
    bool isEnd;

    Trie(){
        isEnd = false;
    }
};

class WordDictionary {
public:

    Trie* root;

    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {

        Trie* node = root;

        for(char c : word){

            int idx = c - 'a';

            if(node->child[idx] == NULL){
                node->child[idx] = new Trie();
            }

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool dfs(string &word, int pos, Trie* node){

        if(pos == word.size()){
            return node->isEnd;
        }

        char ch = word[pos];

        // normal character
        if(ch != '.'){

            int idx = ch - 'a';

            if(node->child[idx] == NULL){
                return false;
            }

            return dfs(word,
                       pos + 1,
                       node->child[idx]);
        }

        // wildcard '.'
        for(int i = 0; i < 26; i++){

            if(node->child[i]){

                if(dfs(word,
                       pos + 1,
                       node->child[i]))
                    return true;
            }
        }

        return false;
    }

    bool search(string word) {

        return dfs(word, 0, root);
    }
};