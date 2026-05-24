/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            auto row=it.second.first;
            auto col=it.second.second;
            TreeNode* temp=it.first;

            m[col][row].insert(temp->val);
            if(temp->left){
                q.push({temp->left,{row+1,col-1}});
                
            }
            if(temp->right){
                q.push({temp->right,{row+1,col+1}});
            }
        }
         
        for(auto col:m){
            vector<int> a;
            for(auto row:col.second){
                for(auto value:row.second){
                    a.push_back(value);
                }}
                ans.push_back(a);
               
            
        }
      return ans;
    }
};