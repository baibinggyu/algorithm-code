#include <vector>
#include <cmath>
constexpr int RIGHT = 1e9 + 1;
using std::vector;
class Solution {
public:
    bool check(int t,double hour,std::vector<int>& dist){
        // -1 t小了
        // 1  t大了
        double time = 0.0;
        for(int i = 0;i < dist.size() - 1;i++){
            time += std::ceil(1.0 * dist[i] / t);
        }
        time += 1.0 * dist.back() /t;
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1,r =  1e9;
        int ans = - 1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            bool test = check(mid,hour,dist);
            if(test){
                ans = mid;
                r = mid -1 ;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};