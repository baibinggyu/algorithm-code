#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int row = matrix.size();
		int col = matrix[0].size();
		int loop = (row >> 1) + 1;
		for(int i = 0;i < loop;++i){
			pair<int,int> start = {i,i};		
			pair<int,int> end = {row - 1 -i,col - 1 -i};
			if(start.second > end.second) break;
			if(start.first > end.first) break;
			if(start.first == end.first){
				for (int j = start.second;j <= end.second;++j)
					res.push_back(matrix[start.first][j]);
				break;
			}else if(start.second == end.second){
				for(int j = start.first;j <= end.first;++j) 
					res.push_back(matrix[j][start.second]);
				break;
			}else{
				for(int j = start.second;j < end.second;++j)
					res.push_back(matrix[start.first][j]);
				for(int j = start.first;j < end.first;++j)
					res.push_back(matrix[j][end.second]);
				for(int j = end.second;j > start.second;--j)
					res.push_back(matrix[end.first][j]);
				for(int j = end.first;j > start.first;--j)
					res.push_back(matrix[j][start.first]);
			} 
			
		}
		return res;
	}
	};
