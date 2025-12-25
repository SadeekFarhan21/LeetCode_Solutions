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
        if(root == nullptr) return {};

        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);

        int level_counter = 0;

        while(!q.empty()){
            int size = q.size();
            vector <int> level;
            level_counter += 1;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
                level.push_back(node -> val);
            }
            if(level_counter % 2 == 0) reverse(level.begin(), level.end());
            levels.push_back(level);
        }
        return levels;
    }
};