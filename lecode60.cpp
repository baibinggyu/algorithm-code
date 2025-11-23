#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        void dictSort(vector<int>& dict){
            int n = dict.size();
            int index = -1;
            int back_index = -1;
            for(int i = n - 1;i > 0;i--)
                if(dict[i] > dict[i-1]) {index = i - 1;break;}
            if(index == -1) {reverse(dict.begin(),dict.end());return;}
            for(int i = n - 1;i > index;i--) if(dict[i] > dict[index]){back_index = i;break;}
            swap(dict[index],dict[back_index]);
            reverse(dict.begin() + index + 1,dict.end());
        }
        string getPermutation(int n, int k) {
            vector<int> dict;
            for(int i = 1;i <= n;i++) dict.push_back(i);      
            while(--k) dictSort(dict);
            string res;
            for(int temp : dict) res += to_string(temp);
            return res;
        }
    };