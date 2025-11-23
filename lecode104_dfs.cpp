struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int dfs(TreeNode* node,int deepth){
        if(node->left == nullptr and node->right == nullptr) return deepth;
        int res = deepth + 1;
        if(node->left and node->right) res = max(dfs(node->left,res),dfs(node->right,res));
        else if (node->left and !node->right) res = dfs(node->left,res);
        else res = dfs(node->right,res);
        return res;
    }
        int maxDepth(TreeNode* root) {
            if(root == nullptr) return 0;
            return dfs(root,1);
        }
    };