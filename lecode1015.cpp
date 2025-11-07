class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1) return 1;
        if(k % 2 == 0 ) return -1;
        if(k % 5 == 0) return -1;
        int SIZE = 1000;
        for(int i = 1;i < SIZE;i++){
            
        }
        return -1;
    }
};
/*
    pre cur
    cur = pre * 10 + 1
    cur mod k = (pre * 10 + 1) mod k

 

*/