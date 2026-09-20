#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
    void dfs(int index,int n,vector<int>& arr,vector<bool>& hash,vector<int>& nums)
	{	
		if(index == n){
			res.push_back(arr);
			return ;
		}
		for(int i = 0;i <  n;++i)
		{
			if(hash[i]) continue;
			hash[i] = true;
			arr.push_back(nums[i]);
			dfs(index + 1,n,arr,hash,nums);
			arr.pop_back();
			hash[i] = false;
		}


	}	

	vector<vector<int>> permute(vector<int>& nums) {
		int n = nums.size();
		vector<bool> hash(n,false);
		vector<int> arr;
		dfs(0,n,arr,hash,nums);
		return  res;
    }
};
