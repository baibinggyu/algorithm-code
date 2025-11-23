#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
constexpr int SIZE = 26;
struct Trie{
    Trie* ch[SIZE];
    bool isEnd;
    Trie(){
        isEnd = false;
        ::memset(ch,0,sizeof ch);
    }
    ~Trie(){
        for(auto &ch : this->ch){
            if(ch != nullptr) delete ch;
        }
    }
};
void insert(Trie* root,std::string& str,int idx){
    if(idx >= str.size()) {
        root->isEnd = true;
        return;
    }
    int nextIndex = str[idx] - 'a';
    if(root->ch[nextIndex] == nullptr) root->ch[nextIndex] = new Trie();
    insert(root->ch[nextIndex],str,idx + 1);
}
bool search(Trie* root,const std::string& str,int idx){
    if(root == nullptr) return false;
    if(idx == str.size()) return root->isEnd;
    int nextIndex = str[idx] - 'a';
    return search(root->ch[nextIndex],str,idx + 1);
}

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n ;std::cin >> n;
    Trie* root[n] = {nullptr};
    for(auto& x : root) x = new Trie();
    for(int i = 0;i < n;i++){
        int m;std::cin >> m;
        for(int j = 0;j < m;j++){
            std::string str;std::cin >> str;
            insert(root[i],str,0);
        }
    }
    int m ;std::cin >> m;
    for(int i = 0;i < m;i++){
        std::string str;std::cin >> str;
        std::vector<int> res;
        for(int j = 0;j < n;j++){
            if(search(root[j],str,0)) res.emplace_back(j + 1);
        }
        if(res.size()){
            for(auto& x : res) std::cout << x << ' ' ;
        }
        std::cout << std::endl;
    }
    for(auto& x: root) delete x;
    return 0;
}