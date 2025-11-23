#include <vector>
using std::vector;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->tree = std::vector<int>(nums.size() << 2,0);
        build(1,0,this->nums.size() - 1);
    }
    
    void update(int index, int val) {
        update_(1,0,nums.size() - 1,index,val);
    }
    
    int sumRange(int left, int right) {
        return treeSearch(1,0,this->nums.size() - 1,left,right);
    }
private:
    int update_(int idx,int l,int r,int index,int val){
        if(l == r) {if(l == index) {tree[idx] = val;return val;}else return tree[idx];}
        int mid = l + ((r - l) >> 1);
        int res = 0;
        if(index <= mid) res += update_(idx << 1,l,mid,index,val);
        if(index > mid) res += update_(idx << 1 | 1,mid + 1,r,index,val);
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
        return res;
    }
    int build(int idx,int left,int right){
        if(left >= right) {tree[idx] = nums[left];return tree[idx];}
        int mid = left + ((right - left) >> 1);
        int res = build(idx << 1,left,mid) + build(idx << 1 | 1,mid + 1,right);
        tree[idx] = res;
        return res;
    }
    int treeSearch(int idx,int l ,int r,int left,int right){
        if(l >= left and r <= right) return tree[idx];
        int res = 0;
        int mid = l + ((r - l) >> 1);
        if(left <= mid) res += treeSearch(idx << 1,l,mid,left,right);
        if(right > mid) res += treeSearch(idx << 1 | 1,mid + 1,r,left,right);
        return res;
    }
    std::vector<int> nums;  
    std::vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */