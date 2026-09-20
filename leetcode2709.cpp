#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 ) return true;
        for(auto& x : nums){
            if(x == 1) return false;
        }
        std::unordered_map<int,int> hash;
        std::vector<int> p(n,0);
        for(int i = 0;i < static_cast<int>(p.size());i++) p[i] = i;
        for(int i = 0;i < static_cast<int>(p.size());i++) p[i] = i;
        for(int i = 0;i < n;i++){
            int x = nums[i];
            for(int j = 2; j <= x / j;j++){
                if(x % j == 0){
                    if(hash.count(j)){
                        union_(hash[j],i,p);
                    }else{
                        hash[j] = i;
                    }
                    while(x % j == 0) x /= j;
                }
            }
            if(x > 1) {
                if(hash.count(x)){
                    union_(hash[x],i,p);
                }else{
                    hash[x] = i;
                }
            }
        }
        int target = 0;
        for(int i = 1;i < n;i++) if(target != find(i,p)) return false;
        return true;
    }
    int find(int n,std::vector<int>& p){
        if(p[n] == n) return n;
        return p[n] = find(p[n],p);
    }
    void union_(int a , int b,std::vector<int>& p){
        int temp01 = find(a,p);
        int temp02 = find(b,p);
        if(temp01 > temp02) std::swap(temp01,temp02);
        p[temp02] = temp01;
    }
};