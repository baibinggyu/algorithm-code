class Solution {
public:
    int gcd(int a,int b){
        if(b == 0) return a;
        return gcd(b , a % b);
    }
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
        return target % gcd(x,y) == 0 ? true : false;
    }
};
