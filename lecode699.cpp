#include <vector>
using std::vector;
struct Segment{
    int val , lazy;
    Segment* left ,* right;
    Segment():val(0),lazy(0),left(nullptr),right(nullptr){}
};
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        std::vector<int> res;
        Segment* root = new Segment();
        int mx = 0;
        for(auto& val : positions){
            int right = val[0] + val[1] - 1;
            int left = val[0];
            int height =  query(this->targetLeft,this->targetRight,val[0],val[0] + val[1] - 1,root);
            update(this->targetLeft,this->targetRight,left,right,height + val[1],root);
            height = query(this->targetLeft,this->targetRight,this->targetLeft,this->targetRight,root);
            mx = std::max(mx,height);
            res.push_back(mx);
        }
        delete root;
        return res;
    }
    int query(int curLeft,int curRight,int l , int r,Segment* cur){
        if(curLeft > curRight or curRight < l or curLeft > r) return 0;
        if(l <= curLeft and curRight <= r) return cur->val;
        push_back(cur);
        int mid = curLeft + ((curRight - curLeft) >> 1);
        return std::max(query(curLeft,mid,l,r,cur->left),query(mid + 1,curRight,l,r,cur->right));
    }
    int update(int curLeft,int curRight,int l ,int r,int h,Segment* cur){
        if(curLeft > curRight or curRight < l or curLeft > r) return 0;
        if(cur == nullptr) cur = new Segment();
        if(l <= curLeft and curRight <= r){
            cur->lazy = h;
            cur->val = h;
            return h;
        }
        int mid = curLeft + ((curRight - curLeft) >> 1);
        cur->val = std::max(update(curLeft,mid,l,r,h,cur->left),update(mid + 1,curRight,l,r,h,cur->right));
        return cur->val;
    }
    void push_back(Segment* cur){
        if(cur->left == nullptr) cur->left = new Segment();
        if(cur->right == nullptr) cur->right = new Segment();
        if(cur->lazy){
            cur->left->lazy = cur->lazy;
            cur->right->lazy = cur->lazy;
            cur->left->val = cur->lazy;
            cur->right->val = cur->lazy;
            cur->lazy = 0;
        }
    }
private:
    const int targetLeft = 0,targetRight = 1e8 + 1e6 + 5;
};