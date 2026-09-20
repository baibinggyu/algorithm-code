#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        void backTracking(const vector<int> & candidates,const int& target,int& n,vector<int> arr,int& sum,int index)
        {
            if(sum == target)
            {   
                res.push_back(arr);
                return ;
            }else if(sum > target) return ;
            for(int i = index;i < n;i++)
            {
                if(i > index && candidates[i] == candidates[i-1]) continue;//去重
                sum += candidates[i];
                arr.push_back(candidates[i]);
                backTracking(candidates,target,n,arr,sum,i+1);
                arr.pop_back();
                sum -= candidates[i];
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<int> arr;
            int sum = 0;
            int n = candidates.size();
            backTracking(candidates,target,n,arr,sum,0);
            return res;
        }
    private:
        vector<vector<int>> res;
    };