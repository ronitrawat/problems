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
        if(!root){
            return ans;
        }
        q.push({root,{0,0}});
        while(!q.empty()){
            int s=q.size();
            while(s--){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int row=it.second.first;
            int col=it.second.second;

            m[col][row].insert(node->val);
            if(node->left){
            q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
            q.push({node->right,{row+1,col+1}});
            }}


        }

        for(auto i:m){
            vector<int> temp;
            for(auto j:i.second){
                temp.insert(temp.end(),j.second.begin(),j.second.end());
                
            }
            ans.push_back(temp);

        }

        return ans;
    }
};