class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 == 0 ? false : true;
    }
};

// 1 , 2, 3 先手必胜利
// 4 必败
// 5 必胜
// 6 必胜
// 7 必胜
// 8 必败