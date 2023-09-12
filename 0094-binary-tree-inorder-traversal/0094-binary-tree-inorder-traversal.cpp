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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>soln;
        TreeNode*temp=root;
        while(temp){
            if(temp->left==NULL){
                soln.push_back(temp->val);
                temp=temp->right;
            }
            else{
                TreeNode*temp1=temp->left;
                while(temp1->right!=NULL && temp1->right!=temp){
                    temp1=temp1->right;
                }
                if(temp1->right==NULL){
                    temp1->right=temp;
                    temp=temp->left;
                }
                else{
                    temp1->right=NULL;
                    soln.push_back(temp->val);
                    temp=temp->right;
                }
            }
        }
        return soln;
    }
};