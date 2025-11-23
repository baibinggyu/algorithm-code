#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
int MOD;
std::vector<int> tree;
std::vector<int> lazyPlus,lazyMultip;
enum{
    MULTIP = 1,
    PLUS,
    OUT
};

int build(int idx,int l ,int r,std::vector<int>& arr){
if(l >= r) return tree[idx] = arr[l];
int mid = l + ((r - l ) >> 1);
int res = ((build(idx << 1,l,mid,arr) % MOD) + (build(idx << 1 | 1,mid + 1,r,arr) % MOD)) % MOD;
tree[idx] = res;
return res; 
}

void pushBack(int idx,int l ,int r){
    int mid = l + ((r - l) >> 1);
    int lc = idx << 1,rc = idx << 1 | 1;
    if(lazyMultip[idx] != 1 || lazyPlus[idx]){
        tree[lc] = (tree[lc] * lazyMultip[idx] + lazyPlus[idx] * (mid - l + 1)) % MOD;
        lazyMultip[lc]  = (lazyMultip[lc] * lazyMultip[idx]) % MOD;
        lazyPlus[lc] = (lazyPlus[lc] * lazyMultip[idx] + lazyPlus[idx]) % MOD; 

        tree[rc] = (tree[rc] * lazyMultip[idx] + lazyPlus[idx] * (r - mid)) % MOD;
        lazyMultip[rc] = (lazyMultip[idx] * lazyMultip[rc]) % MOD;
        lazyPlus[rc] = (lazyPlus[rc] * lazyMultip[idx] + lazyPlus[idx]) % MOD;

        lazyMultip[idx] = 1;
        lazyPlus[idx] = 0;
    }
}

void updataMultip(int idx,int l, int r,int left,int right,int val){
   if(left <= l and r <= right){tree[idx] *= val;lazyMultip[idx] *= val;lazyPlus[idx] *= val;return;}
    int mid = l + ((r - l) >> 1);
    if(left <= mid) updataMultip(idx << 1,l,mid,left,right,val);
    if(mid < right) updataMultip(idx << 1 | 1,mid + 1,r,left,right,val);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

void updataPlus(int idx,int l ,int r ,int left ,int right,int val){
    if(left <= l and r <= right) {tree[idx] += val * (r - l + 1);lazyPlus[idx] += val;return;}
    int mid = l + ((r - l) >> 1);
    if(left <= mid) updataPlus(idx << 1,l,mid,left,right,val);
    if(mid < right) updataPlus(idx << 1  | 1,mid + 1,r,left,right,val);
    tree[idx] = tree[idx << 1] + tree[idx << 1  |1];
}

int query(int idx,int l , int r,int left,int right){
    pushBack(idx,l,r);
    if(left <= l and r <= right) return tree[idx];
    int res = 0;
    int mid = l + ((r - l) >> 1);
    if(left <= mid) res += query(idx << 1,l,mid,left,right) % MOD;
    if(right > mid) res += query(idx << 1 | 1,mid + 1,r,left,right) % MOD;
    tree[idx] = res;
    return res % MOD;
}

signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n , q;
    std::cin >> n >> q >> MOD;
    std::vector<int> arr(n);
    for(int i = 0;i < n;i++) std::cin >> arr[i];
    tree.assign(n << 2,0);
    lazyMultip.assign(n << 2,1),lazyPlus.assign(n << 2,0);
    build(1,0,arr.size() - 1,arr);
    while(q--){
        int select;
        std::cin >> select;
        if(select == MULTIP) {int x , y ,k;std::cin >> x >> y >> k;updataMultip(1,0,arr.size() - 1,x - 1, y - 1,k);}
        else if(select == PLUS){int x, y , k;std::cin >> x >> y >> k;updataPlus(1,0,arr.size() - 1,x - 1,y - 1,k);}
        else {int x, y;std::cin >> x >> y;std::cout << query(1,0,arr.size() - 1,x - 1,y - 1) << std::endl;}
    }
    return 0;
}