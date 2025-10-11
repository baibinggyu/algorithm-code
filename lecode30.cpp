    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
        public:
            vector<int> findSubstring(string s, vector<string>& words) {
            int n = s.size(),m = words.size(),word_len = words[0].size();
            vector<int> res;
            if(n < m * word_len) return res;
            unordered_map<string,int> hash;
            for(string& temp:words) hash[temp]++;
            vector<unordered_map<string,int>> multiWindow(word_len);//多窗口滑动
            for(int i = 0;i < word_len && i + m * word_len < n + 1;i++)
            {
                    for(int j = i;j < i + m * word_len && j + word_len < n + 1;j += word_len)
                    {
                        string temp = s.substr(j,word_len);
                        multiWindow[i][temp]++;
                    }
                    if(multiWindow[i] == hash) res.emplace_back(i);
            }
            for(int i = word_len;i + m * word_len < n + 1;i++)
            {
                int index = i % word_len;
                string front = s.substr(i - word_len,word_len);
                string back = s.substr(i + (m-1)*word_len,word_len);
                if(--multiWindow[index][front] == 0) multiWindow[index].erase(front);
                multiWindow[index][back]++;
                if(multiWindow[index] == hash) res.emplace_back(i);
            }   
            return res;
            }
        };