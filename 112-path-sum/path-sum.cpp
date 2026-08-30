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
bool calc(TreeNode* root, int targetSum, int sum)
{

    if(root==NULL)return false;
    sum = sum+root->val;
          if (root->left == NULL && root->right == NULL)
        {
            return sum == targetSum;
        }
   return calc(root->left,targetSum,sum) ||
    calc(root->right,targetSum,sum);

    return false;
}
    bool hasPathSum(TreeNode* root, int targetSum) {

      return  calc(root,targetSum,0);
        
    }
};