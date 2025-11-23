#include <vector>
#include <utility>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n,vector<int>(n));
            int count = 1;
            int loop = n >> 1;
            if(n & 1){ // 奇数
                for(int i = 0;i < n;i++){
                   int begin = i;
                   int end = n - 1 - i;
                    for(int j = begin;j < end;j++) res[begin][j] = count++;
                    for(int j = begin;j < end;j++) res[j][end] = count++;
                    for(int j = end;j > begin;j--) res[end][j] = count++;
                    for(int j = end;j > begin;j--) res[j][begin] = count++;
                }
            }else{
                for(int i = 0;i <= n;i++){
                    int begin = i;
                    int end = n - 1 - i;
                     for(int j = begin;j < end;j++) res[begin][j] = count++;
                     for(int j = begin;j < end;j++) res[j][end] = count++;
                     for(int j = end;j > begin;j--) res[end][j] = count++;
                     for(int j = end;j > begin;j--) res[j][begin] = count++;
                 }
                }
                if (n & 1) res[loop][loop] = count;
            return res;
            }
            
            
    };