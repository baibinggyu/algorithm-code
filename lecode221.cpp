#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp = vector<vector<int>>(n,vector<int>(m,0));
        int res = 0;
        for(int i = 0;i < n;i++){
            //std::string s(count, char);
            dp[i][0] = std::stoi(std::string(1,matrix[i][0]));
            if (dp[i][0]) res = 1;
        }
        for(int i = 0;i < m;i++){
            dp[0][i] = std::stoi(std::string(1,matrix[0][i]));
            if(dp[0][i]) res = 1;
        }
        for(int i = 1;i < n;i++){
            int last_i = i - 1;
            for(int j = 1;j < m;j++){
                if(matrix[i][j] == '0') continue;
                int last_j = j - 1;
                int len = dp[last_i][last_j];     
                for (int k = 0;k <= len;k++){
                    if(matrix[i][j - k] == '1' && matrix[i - k][j] == '1'){
                        dp[i][j]++;
                    }else{
                        break;
                    }
                }
                res = std::max(res,dp[i][j]);
            }
        }
        return res * res;
    }
private:
    vector<vector<int>> dp;
};