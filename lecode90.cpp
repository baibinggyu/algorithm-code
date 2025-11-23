#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(int curIndex,std::vector<int>& arr,std::vector<int>& nums){
        if (curIndex >= nums.size()){
            res.push_back(arr);
            return ;
        }
        arr.push_back(nums[curIndex]);
        dfs(curIndex + 1,arr,nums);
        arr.pop_back();
        while(curIndex + 1 < nums.size() && nums[curIndex] == nums[curIndex + 1]) curIndex++;
        dfs(curIndex + 1,arr,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(),nums.end(),[](const int a,const int b)->bool{return a < b;});
        std::vector<int> arr;
        dfs(0,arr,nums);
        return res;
    }
private:
    std::vector<std::vector<int>> res;
};