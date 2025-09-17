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
    vector<vector<int>> answer;
    void dfs(TreeNode* root, vector <int> path, int total, int targetSum){
        if(!root){
            return;
        }

        total += (root -> val);
        path.push_back(root -> val);

        if(root && !root -> left && !root -> right && total == targetSum){
            answer.push_back(path);
        }
        if(root -> left) dfs(root -> left, path, total, targetSum);
        if(root -> right) dfs(root -> right, path, total, targetSum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> path;
        dfs(root, path, 0, targetSum);
        return answer;   
    }
};