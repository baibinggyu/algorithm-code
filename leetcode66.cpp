#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for(vector<int>::reverse_iterator it = digits.rbegin();it != digits.rend();it++){
        if(carry) *it += 1;
        if(*it >  9) {carry = 1;*it %= 10;}
        else carry = 0;
    }
    if(carry) digits.insert(digits.begin(),1);
    return digits;

}
};