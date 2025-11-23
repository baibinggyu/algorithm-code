#include <algorithm>
#include <iostream>
#include <vector>
std::vector<long long> tree,lazy;

long long build(std::vector<int>& arr,int idx , int l , int r){
    if(l == r) {tree[idx] = arr[l]; return tree[idx];}
    long long res = 0;
    int mid = l + ((r - l) >> 1);
    res += build(arr,idx << 1,l,mid);
    res += build(arr,idx << 1 | 1,mid + 1,r); 
    tree[idx] = res;
    return res;
}
void push_up(int idx){
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

void push_down(int idx,int l,int r){
    if(lazy[idx]){
        int mid = l + ((r - l) >> 1);
        tree[idx << 1] += lazy[idx] * (mid - l + 1);
        lazy[idx << 1] += lazy[idx];
        tree[idx << 1 | 1] += lazy[idx] * (r - mid); 
        lazy[idx << 1 | 1] += lazy[idx];
        lazy[idx] = 0;
    }
}
void update(int idx,int l , int r,int left ,int right,long long val){
    if(left <= l and r <= right) {
        tree[idx] += (r - l + 1) * val;
        lazy[idx] += val;
        return;
    }
    push_down(idx,l,r);
    int mid = l + ((r - l) >> 1);
    if(left <= mid) update(idx << 1,l , mid,left,right,val);
    if(right > mid ) update(idx << 1 | 1,mid + 1,r,left,right,val);
    push_up(idx);
}

long long  query(int idx,int l , int r,int left,int right){
    if(left <= l and r <= right) return tree[idx];
    push_down(idx,l,r); 
    long long res = 0;
    int mid =  l + ((r - l) >> 1);
    if(left <= mid) res += query(idx << 1,l , mid , left,right);
    if(right > mid ) res += query(idx << 1 | 1,mid + 1,r,left,right);
    return res;
}

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n , m;
    std::cin >> n >> m;
    std::vector<int> arr(n);
    std::for_each(arr.begin(),arr.end(),[](auto& it){std::cin >> it;});
    tree = std::vector<long long >(n << 2,0),lazy = std::vector<long long>(n << 2,0);
    build(arr,1,0,arr.size() - 1);
    while(m--){
        int flag;
        std::cin >> flag;
        if(flag == 1){
            int x , y , k;
            std::cin >> x >> y >> k;    
            update(1,0,arr.size() - 1,x - 1, y - 1,k);
            continue;
        }
        int x , y;
        std::cin >> x >> y;
        std::cout << query(1,0,arr.size() - 1,x - 1 , y - 1) << std::endl;
    }
    return 0;
}