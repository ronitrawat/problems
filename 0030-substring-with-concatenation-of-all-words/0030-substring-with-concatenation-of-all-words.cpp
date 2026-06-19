class TrieNode{
public:
    TrieNode* child[26];
    int id;

    TrieNode(){
        memset(child,0,sizeof(child));
        id=-1;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void insert(string &s,int idx){

        TrieNode* cur=root;

        for(char c:s){

            int x=c-'a';

            if(!cur->child[x])
                cur->child[x]=new TrieNode();

            cur=cur->child[x];
        }

        cur->id=idx;
    }

    int search(string &s){

        TrieNode* cur=root;

        for(char c:s){

            int x=c-'a';

            if(!cur->child[x])
                return -1;

            cur=cur->child[x];
        }

        return cur->id;
    }
};

class Solution {
public:

    vector<int> findSubstring(string s,
                              vector<string>& words) {

        vector<int> ans;

        int n=s.size();

        int m=words.size();

        int k=words[0].size();

        Trie trie;

        vector<int> target(m,1);

        unordered_map<string,int> mp;

        int idx=0;

        for(auto &w:words){

            if(!mp.count(w)){
                mp[w]=idx;
                trie.insert(w,idx++);
            }
        }

        vector<int> freq(idx);

        for(auto &w:words)
            freq[mp[w]]++;

        int total=m*k;

        for(int i=0;i+total<=n;i++){

            vector<int> seen(idx,0);

            int j=0;

            for(;j<m;j++){

                string cur=
                s.substr(i+j*k,k);

                int id=trie.search(cur);

                if(id==-1)
                    break;

                seen[id]++;

                if(seen[id] > freq[id])
                    break;
            }

            if(j==m)
                ans.push_back(i);
        }

        return ans;
    }
};