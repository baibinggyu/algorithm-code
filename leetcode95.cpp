struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>



using std::vector;
class Solution {
public:
    std::vector<TreeNode*> generateTrees(int start,int end){
        if(start > end) return {nullptr};
        std::vector<TreeNode*> res;
        for(int i = start;i <= end;i++){
            std::vector<TreeNode*> leftNode = generateTrees(start,i - 1);
            std::vector<TreeNode*> rightNode = generateTrees(i + 1,end);
            for(TreeNode* left : leftNode){
                for (TreeNode* right : rightNode){
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    res.emplace_back(node);
                }
            }

        }
        return res;

    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1,n);
    }
};