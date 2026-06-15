class Trie {
public:
    Trie* child[26];
    bool isEnd;

    Trie() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }

    void insert(string word) {
        Trie* node = this;

        for (char c : word) {
            int idx = c - 'a';

            if (node->child[idx] == NULL) {
                node->child[idx] = new Trie();
            }

            node = node->child[idx];
        }

        node->isEnd = true;
    }
};

class Solution {
public:
    string search(string word, Trie* root) {

        Trie* node = root;
        string prefix = "";

        for (char c : word) {

            int idx = c - 'a';

            if (node->child[idx] == NULL) {
                return word;
            }

            node = node->child[idx];
            prefix += c;

            if (node->isEnd) {
                return prefix;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        Trie* root = new Trie();

        for (string word : dictionary) {
            root->insert(word);
        }

        stringstream ss(sentence);

        string word;
        string ans = "";

        while (ss >> word) {

            if (!ans.empty()) {
                ans += " ";
            }

            ans += search(word, root);
        }

        return ans;
    }
};