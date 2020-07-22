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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int> >ans;
        if(root == NULL)    return ans;
        queue<TreeNode*>q;
        vector<int>temp;
        
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            temp.clear();
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front(); q.pop();
                temp.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level&1) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            level++;
        }
        
        return ans;
    }
};