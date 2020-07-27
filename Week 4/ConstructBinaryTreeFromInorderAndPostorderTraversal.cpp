// Time complexity :- O(n)
// Space complexity :- O(n)
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
    unordered_map<int, int>in;
public:
    TreeNode* build(vector<int>&inorder, vector<int>&postorder, int l, int r, int &post_id)
    {
        if(l > r)   return NULL;
        
        TreeNode* node = new TreeNode(postorder[post_id]);
        post_id--;
        int id = in[node->val];
        node->right = build(inorder, postorder, id+1, r, post_id);
        node->left = build(inorder, postorder, l, id-1, post_id);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int l = 0, r = n-1;
        for(int i=0;i<n;i++)
        {
            in[inorder[i]] = i;
            // post[postorder[i]] = i;
        }
        int post_id = n-1;
        return build(inorder, postorder, l, r, post_id);
        
    }
};