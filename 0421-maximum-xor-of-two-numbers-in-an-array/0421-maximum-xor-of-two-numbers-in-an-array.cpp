class Trie{ 
    public:
       Trie* child[2];

       Trie(){
        child[0]=child[1]=NULL;
       }



   void insert(int num){
     Trie* node=this;
     for( int i=31;i>=0;i--){
        int bit=(num>>i) & 1;
        if(node->child[bit]==NULL){
            node->child[bit]=new Trie();
        }
        node=node->child[bit];
     }
   }

   int getMax( int num,Trie* node){
    int ans=0;
    for(int i=31;i>=0;i--){
        int bit =(num>>i) & 1;
        if(node->child[1-bit]){
            ans|=(1<<i);
            node=node->child[1-bit];
        }
        else{
            node=node->child[bit];
        }
    }
    return ans;
   }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root=new Trie();
        for(auto n:nums){
            root->insert(n);
        }

        int maxi=0;
        for(auto n: nums){
            maxi=max(maxi,root->getMax(n,root));
        }
        return maxi;
    }
};