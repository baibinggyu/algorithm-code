#include <vector>
#include <memory>
using std::vector;
constexpr int SIZE = 1e8 + 1e6 + 5;
struct Node{
    int lazy;
    int height;
    Node* left , *right;
    Node():lazy(0),height(-1){}
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int end = 0;
        std::vector<int> res;
        Node* root = new Node();
        for(auto& val : positions){
            end = std::max(end,val[0] + val[1] - 1);
            update(0,SIZE,val[0],val[0] + val[1] - 1,val[1],root);
            int insert = 0;
            for(int i = 0;i < end + 1;i++){
                insert = std::max(0,quey(0,end,i,i,root));
            }
            res.emplace_back(insert);
        }
        delete root;
        return res;
    }   
    void push_back(Node* cur){
        if(!cur->left) cur->left = new Node();
        if(!cur->right) cur->right = new Node();
        if(cur->lazy){
            cur->left->lazy = cur->lazy;
            cur->left->height = cur->left->height + cur->lazy;
            cur->right->lazy = cur->lazy;
            cur->right->height = cur->right->height + cur->lazy;
            cur->lazy = 0;
        }
    }
    int quey(int l,int r,int left,int right,Node* cur){
        if(l > r) return 0;
        if(l == r) return cur->height;
        push_back(cur);
        int mid = l + ((r - l) >> 1);
        return std::max(quey(l , mid,left,right,cur->left),quey(mid + 1,r,left,right,cur->right));
    }
    void update(int l,int r,int left,int right,int height,Node* cur){
        if(l > r) return;
    }
};