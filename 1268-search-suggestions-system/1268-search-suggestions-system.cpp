class Trie{
public:

    Trie* child[26] = {};
    vector<string> sug;
};

class Solution {
public:

    Trie* root = new Trie();

    void insert(string &word){

        Trie* node = root;

        for(char c : word){

            int idx = c - 'a';

            if(node->child[idx] == NULL)
                node->child[idx] = new Trie();

            node = node->child[idx];

            if(node->sug.size() < 3)
                node->sug.push_back(word);
        }
    }

    vector<vector<string>> suggestedProducts(
            vector<string>& products,
            string searchWord) {

        sort(products.begin(),
             products.end());

        for(string &word : products){
            insert(word);
        }

        vector<vector<string>> ans;

        Trie* node = root;

        for(char c : searchWord){

            int idx = c - 'a';

            if(node != NULL &&
               node->child[idx] != NULL){

                node = node->child[idx];

                ans.push_back(node->sug);
            }
            else{

                node = NULL;

                ans.push_back({});
            }
        }

        return ans;
    }
};