class Trie{
public:

    Trie* child[4]={};

    int cnt=0;
};

class Solution {
public:

    int getIdx(char c){

        if(c=='A') return 0;
        if(c=='C') return 1;
        if(c=='G') return 2;

        return 3;
    }

    vector<string> findRepeatedDnaSequences(string s) {

        Trie* root = new Trie();

        vector<string> ans;

        int n = s.size();

        for(int i=0;i+9<n;i++){

            Trie* node = root;

            string cur = s.substr(i,10);

            for(char c : cur){

                int idx = getIdx(c);

                if(node->child[idx]==NULL)
                    node->child[idx]=new Trie();

                node=node->child[idx];
            }

            node->cnt++;

            if(node->cnt==2)
                ans.push_back(cur);
        }

        return ans;
    }
};