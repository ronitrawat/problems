class Trie{
public:

    Trie* child[26] = {};

    int freq = 0;
};

class Solution {
public:

    Trie* root = new Trie();

    void insert(string word){

        Trie* node = root;

        for(char c : word){

            int idx = c - 'a';

            if(node->child[idx] == NULL)
                node->child[idx] = new Trie();

            node = node->child[idx];
        }

        node->freq++;
    }

    void dfs(Trie* node,
             string cur,
             vector<pair<string,int>>& words){

        if(node->freq > 0){

            words.push_back(
                {cur,node->freq}
            );
        }

        for(int i=0;i<26;i++){

            if(node->child[i]){

                dfs(node->child[i],
                    cur + char('a'+i),
                    words);
            }
        }
    }

    static bool cmp(pair<string,int>& a,
                    pair<string,int>& b){

        if(a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    }

    vector<string> topKFrequent(
            vector<string>& words,
            int k) {

        for(auto &word : words)
            insert(word);

        vector<pair<string,int>> allWords;

        dfs(root,"",allWords);

        sort(allWords.begin(),
             allWords.end(),
             cmp);

        vector<string> ans;

        for(int i=0;i<k;i++)
            ans.push_back(
                allWords[i].first
            );

        return ans;
    }
};