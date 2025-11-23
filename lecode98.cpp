 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
#include <iostream>
#include <vector>
class Solution {
public:
    void dfs(TreeNode* cur,std::vector<int>& arr){
        if(cur == nullptr) return;
        dfs(cur->left,arr);
        arr.push_back(cur->val);
        dfs(cur->right,arr);
    }
    bool isValidBST(TreeNode* root) {
        std::vector<int> arr;
        dfs(root,arr);
        for(int i = 1;i < arr.size();i++) 
            if(arr[i] <= arr[i - 1]) return false;
        return true;
    }
};