#include <vector>
#include <iostream>
#include <deque>
using std::vector;
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        std::vector<long long> pre(n,0);
        pre.front() = runningCosts.front();
        for(int i = 1;i < n;i++) pre[i] = pre[i - 1] + runningCosts[i];
        std::deque<int> dq;
        dq.push_back(0);
        int l = 0;
        int res = 0;
        if(chargeTimes.front() + runningCosts.front() <= budget) res = 1;
        for(int  r = 1;r < n;r++){
            while(not dq.empty() and chargeTimes[dq.back()] < chargeTimes[r]) dq.pop_back();
            dq.push_back(r);
            long long calc = chargeTimes[dq.front()] + (r - l + 1) * 1ll * (pre[r] - pre[l] + runningCosts[l]);
            while(calc > budget * 1ll and l < r){
                l++;
                while(not dq.empty() and dq.front() < l) dq.pop_front(); 
                calc = chargeTimes[dq.front()] + (r - l + 1)* 1ll * (pre[r] - pre[l] + runningCosts[l]);
            }
            if(calc > budget * 1ll) continue;
            res = std::max(res,r - l + 1);
        }
        return res;

    }
};