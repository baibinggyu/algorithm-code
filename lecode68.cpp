#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<int> table;
        for(string temp : words) table.push_back(temp.size());
        int curCount = 0;
        vector<string> temp;
        int last_index = words.size() - 1;
        int cnt = 0; // 单词
        for(int i = 0;i < words.size();i++){
            curCount += table[i] + 1;
            cnt++;  
            temp.push_back(words[i]);
            
            if(curCount >= maxWidth){
                bool flag = false; // 标记最后一行 
                int spaceCount;
                int space;
                int moreSpace;
                bool isRomove = true;
                if(curCount - 1 == maxWidth){// 刚好多一个空格
                    spaceCount = cnt - 1;
                    isRomove = false;
                    flag = true;
                }else if(curCount == maxWidth){ // 刚好
                    spaceCount = cnt;
                    isRomove = false;
                    flag = true;
                }else{ // 多一组数据
                    cnt --;
                    curCount -= (table[i] + 1);
                    spaceCount = maxWidth - curCount + cnt;
                    temp.pop_back(); //  flag true isRomove true
                }
                if(i == last_index && !isRomove) continue;
                int loop = temp.size();
                if(loop - 1){
                    space = spaceCount / (loop - 1);
                    moreSpace = spaceCount % (loop - 1);
                }else{
                    space = spaceCount; 
                    moreSpace = 0;
                }   
            string str;
            str += temp[0];
            if(moreSpace){moreSpace--;str += ' ';}
            for(int i = 0;i < space;i++) str += ' ';
            for(int i = 1;i < loop;i++){
                str += temp[i];
                if(str.size() >= maxWidth) continue;
                for(int j = 0;j < space;j++) str += ' ';
                if(moreSpace) {moreSpace--;str += ' ';}
            }
            res.push_back(str);
            temp.clear();
            if(isRomove){
                temp.push_back(words[i]);
                cnt = 1;
                curCount = words[i].size() + 1;
            }else{
                 cnt = 0;
                curCount = 0;
            }
               
            }
        }
        if(!temp.empty())
        {
            string line;
            int n = temp.size();
            for(int i = 0;i < n;i++){
                line += temp[i];
                if(i + 1 != n) line += ' ' ;
            }
             while(line.size() < maxWidth) line += ' ';
             res.push_back(line);
        } 
        
        return res;
    }
};
