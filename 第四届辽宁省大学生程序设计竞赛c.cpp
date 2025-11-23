#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define int long long

int n;
void boomHurt(int cur,int& deathBoomNotRealse,std::vector<int>&p,std::vector<int>& boom,std::vector<bool>& isDeath){
    if(isDeath[cur]) return;
    isDeath[cur] = true;
    deathBoomNotRealse += boom[cur];
    for(int i = 1;i <= n;i++){
        if(isDeath[i]) continue;
        if(p[i] <= deathBoomNotRealse){
            boomHurt(i,deathBoomNotRealse,p,boom,isDeath);            
        }
    }
}

signed main(void){
    std::cin >> n;
    std::vector<int> p(n + 1,0),boom(n + 1,0);    // 血量
    int sum = 0;
    std::priority_queue<std::pair<int,int>> pq; // boom index
    for(int i = 1;i <= n;i++) std::cin >> p[i] >> boom[i],sum += boom[i];   

    int res = 0;
    std::vector<bool> isDeath(n + 1,false);
    std::vector<int> canNotDeath;
    for(int i = 1;i <= n;i++){if(sum - boom[i] < p[i]) {res++; canNotDeath.push_back(i);}else pq.push(std::make_pair(boom[i],i));}
    int deathBoomNotRealse = 0;
    for(auto x : canNotDeath){boomHurt(x,deathBoomNotRealse,p,boom,isDeath);}
    
    while(not pq.empty()){
        auto [x,y] = pq.top();pq.pop();
        if(isDeath[y]) continue;
        deathBoomNotRealse += x;
        isDeath[y] = true;
        res++;
        for(int i = 1;i <= n;i++){
            if(isDeath[i]) continue;
            if(p[i] <= deathBoomNotRealse){
                boomHurt(i,deathBoomNotRealse,p,boom,isDeath);
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}

// 特例
// 5
// 10 1
// 10 1
// 1 9
// 10 1
// 10 1