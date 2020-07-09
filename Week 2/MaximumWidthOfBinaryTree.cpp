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
// Time complexity :- O(n)
// Space complexity :- O(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)    return 0;
        int res = 1;
        queue<pair<TreeNode*, int> >q;    //{val, index}
        q.push({root, 0});
        
        while(!q.empty())
        {
            int sz = q.size();
            int start = q.front().second;
            int last = q.back().second;
            res = max(res, last - start + 1);
            while(sz--)
            {
                auto node = q.front();q.pop();
                int id = node.second - start;
                if(node.first->left)  q.push({node.first->left, 2*id + 1});
                if(node.first->right) q.push({node.first->right, 2*id + 2});
            }
        }
        return res;
    }
};