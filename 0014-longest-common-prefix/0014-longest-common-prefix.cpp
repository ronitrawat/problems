class Trie{
public:

    Trie* child[26] = {};

    bool isEnd = false;
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

        node->isEnd = true;
    }

    int countChild(Trie* node,
                   int &idx){

        int cnt = 0;

        for(int i=0;i<26;i++){

            if(node->child[i]){

                cnt++;
                idx = i;
            }
        }

        return cnt;
    }

    string longestCommonPrefix(
            vector<string>& strs) {

        for(auto &s : strs)
            insert(s);

        string ans = "";

        Trie* node = root;

        while(node){

            int idx = -1;

            int cnt =
            countChild(node, idx);

            if(cnt != 1)
                break;

            if(node->isEnd)
                break;

            ans += char('a' + idx);

            node = node->child[idx];
        }

        return ans;
    }
};