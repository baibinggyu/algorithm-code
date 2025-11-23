#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        void backTracking(int& sum,int& target,vector<int>& arr,const vector<int>& candiadates,int index,int size)
        {
            if(sum == target){
                 res.push_back(arr);
                 return ;
            }
            else if (sum > target) return;
            for(int i = index;i < size;i++)
            {
                sum += candiadates[i];
                arr.push_back(candiadates[i]);
                backTracking(sum,target,arr,candiadates,i,size);
                arr.pop_back();
                sum -= candiadates[i];
            }
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<int> arr;
            int sum = 0;
            backTracking(sum,target,arr,candidates,0,candidates.size());
            return res;
        }
    private:
        vector<vector<int>> res;
    };