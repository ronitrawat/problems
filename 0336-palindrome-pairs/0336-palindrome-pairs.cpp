class Trie{
public:

    Trie* child[26]={};

    int idx=-1;

    vector<int> pal;
};

class Solution {
public:

    Trie* root=new Trie();

    bool isPal(
        string &s,
        int l,
        int r){

        while(l<r){

            if(s[l++]!=s[r--])
                return false;
        }

        return true;
    }

    void insert(
        string word,
        int id){

        Trie* node=root;

        for(int i=word.size()-1;
            i>=0;
            i--){

            if(isPal(word,0,i))
                node->pal.push_back(id);

            int idx=
            word[i]-'a';

            if(!node->child[idx])
                node->child[idx]
                =new Trie();

            node=node->child[idx];
        }

        node->idx=id;
        node->pal.push_back(id);
    }

    vector<vector<int>>
    palindromePairs(
        vector<string>& words) {

        for(int i=0;
            i<words.size();
            i++)
            insert(words[i],i);

        vector<vector<int>> ans;

        for(int i=0;
            i<words.size();
            i++){

            Trie* node=root;

            string word=
            words[i];

            int j=0;

            for(;j<word.size();
                j++){

                if(node->idx!=-1 &&
                   node->idx!=i &&
                   isPal(
                     word,
                     j,
                     word.size()-1))
                {

                    ans.push_back(
                    {i,node->idx});
                }

                int idx=
                word[j]-'a';

                if(!node->child[idx])
                    break;

                node=
                node->child[idx];
            }

            if(j==word.size()){

                for(int x:
                    node->pal){

                    if(x!=i)
                        ans.push_back(
                        {i,x});
                }
            }
        }

        return ans;
    }
};