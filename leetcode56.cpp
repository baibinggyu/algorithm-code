#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end(),[](vector<int>& arr01,vector<int>& arr02)->bool{return arr01[0] < arr02[0];});
            vector<vector<int>> res;
            int last = intervals[0][0],cur = intervals[0][1];
            int n = intervals.size();
            for(int i = 1;i < n;++i){
                if(cur < intervals[i][0]){
                    res.push_back({last,cur});
                    last = intervals[i][0];
                    cur = intervals[i][1];
                    continue;
                }
            if(cur < intervals[i][1]) cur = intervals[i][1];

            }
            res.push_back({last,cur});
            return res;
            
        }
    };