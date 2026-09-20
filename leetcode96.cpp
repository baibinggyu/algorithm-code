#include <iostream>
class Solution {
public:
    int numTrees(int n) {
        return numTrees(1,n);
    }   
    int numTrees(int start,int end){
        if (start >= end) return 1;
        int res = 0;
        for(int i = start;i <= end;i++){
            res += (numTrees(start,i - 1) * numTrees(i + 1,end));            
        }
        return res;
    }
};
