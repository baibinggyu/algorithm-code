#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> res;
            vector<vector<int>>::iterator it = intervals.begin();
            while(it != intervals.end()){
                if((*it)[0] > newInterval[0]) break;
                ++it;
            }
            intervals.insert(it,newInterval);
            int last = intervals[0][0],cur = intervals[0][1];
            int n = intervals.size();           
            for(int i = 1;i < n;++i)
            {
                if(cur >= intervals[i][0] and cur <= intervals[i][1]){
                    cur = intervals[i][1];
                    continue;
                }else if(cur > intervals[i][1]) continue;
                res.push_back({last,cur});
                last = intervals[i][0],cur = intervals[i][1];
             
            }
            res.push_back({last,cur});
            return res;
        }
    };