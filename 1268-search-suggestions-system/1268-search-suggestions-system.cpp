class Trie{
public:
    Trie* child[26] = {};
    bool isEnd;

    Trie(){
        isEnd = false;
    }

    void insert(string word){

        Trie* node = this;

        for(char c : word){

            int idx = c - 'a';

            if(node->child[idx] == NULL){
                node->child[idx] = new Trie();
            }

            node = node->child[idx];
        }

        node->isEnd = true;
    }
};

class Solution {
public:

    void dfs(Trie* node,
             string curr,
             vector<string>& words){

        if(words.size() == 3)
            return;

        if(node->isEnd){
            words.push_back(curr);
        }

        for(int i=0;i<26;i++){

            if(node->child[i]){

                dfs(node->child[i],
                    curr + char('a'+i),
                    words);
            }
        }
    }

    vector<string> search(Trie* root,
                          string prefix){

        Trie* node = root;

        for(char c : prefix){

            int idx = c - 'a';

            if(node->child[idx] == NULL){
                return {};
            }

            node = node->child[idx];
        }

        vector<string> words;

        dfs(node,prefix,words);

        return words;
    }

    vector<vector<string>> suggestedProducts(
            vector<string>& products,
            string searchWord) {

        Trie* root = new Trie();

        for(string product : products){
            root->insert(product);
        }

        vector<vector<string>> ans;

        string prefix = "";

        for(char c : searchWord){

            prefix += c;

            ans.push_back(
                search(root,prefix)
            );
        }

        return ans;
    }
};