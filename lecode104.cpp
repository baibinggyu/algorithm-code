struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <queue>
#include <algorithm>
class Solution {
    public:
        int maxDepth(TreeNode* root) {
           if(root == nullptr) return 0;
            std::queue<TreeNode*> que;
            que.push(root);
            int res = 0;
            while(!que.empty()){
                int n = que.size();
                for(int i = 0;i < n;i++)
                {
                    TreeNode* node = que.front();
                    que.pop();
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
                res++;
            }
            return res;
        }
    };