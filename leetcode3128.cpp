#include <vector>
using std::vector;
constexpr int N = 1e6 + 5;
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        std::vector<int> row(grid.size()),col(grid.front().size());
        int rowLen = grid.size(),colLen = grid.front().size();
        for(int i = 0;i < static_cast<int>(grid.size());i++)
        {
            int count = 0;
            for(auto& x : grid[i]) count += x;
            row[i] = count;
        }
        for(int i = 0;i < static_cast<int>(grid.front().size());i++){
            int count = 0;
            for(int j = 0;j < static_cast<int>(grid.size());j++){
                count += grid[j][i];
            }
            col[i] = count;
        }
        long long  res = 0 ;
        for(int i = 0;i < static_cast<int>(grid.size());i++)
            for(int j = 0;j < static_cast<int>(grid.front().size());j++)
                if(grid[i][j]){
                    int a = row[i],b = col[j];
                    res += (a - 1) * 1l * (b - 1);
                }
        return res;
    }
    
};