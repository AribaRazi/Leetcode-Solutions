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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ord;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }

        q.push(root);
        while(q.size()>0)
        {
            int currsize=q.size();
            for(int i=0;i<currsize;i++)
            {
                // TreeNode* curr = q.pop();    
                            TreeNode* curr=q.front();
            q.pop();                  // 

                ord.push_back(curr->val);
                if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            }
            ans.push_back(ord);
            ord.clear();

        }
        return ans;
        
    }
};