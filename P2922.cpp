#include <vector>
#include <algorithm>
#include <iostream>
struct Trie{
    int next[2];
    int count;
    int end;
    Trie(){next[0] = next[1] = -1,count = 0,end = 0;}
};
std::vector<Trie> trie(1,Trie());
void insert(const std::vector<int>& arr){
    int p = 0;
    for(auto& x : arr){
        if(trie[p].next[x] == -1){
            trie[p].next[x] = trie.size();
            trie.emplace_back(Trie());
        }
        p = trie[p].next[x];
        trie[p].count++;
    }
    trie[p].end++;
}
int query(const std::vector<int>& arr){
    int p = 0;
    int res = 0;
    for(auto& x : arr){
        res += trie[p].end;
        if(trie[p].next[x] == -1){
            return res;
        }
        p = trie[p].next[x];
    }
    return trie[p].count + res;
}


int main(void){
    int m , n;std::cin >> m >> n;
    for(int i = 0;i < m;i++){
        int count;std::cin >> count;
        std::vector<int> arr(count);
        for(int j = 0;j < count;j++) std::cin >> arr[j];
        insert(arr);
    }    
    for(int i = 0;i < n;i++){
        int count;std::cin >> count;
        std::vector<int> arr(count);
        for(int j = 0;j < count;j++) std::cin >> arr[j];
        std::cout << query(arr) << std::endl;
    }

    return 0;
}