from typing import List
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word = set(wordDict)
        # 索引为start val为end
        vis = {}
        n = len(s)
        def dfs(idx : int):
            if idx == len(s):
                return True
            if  idx in vis:
                return vis[idx]
            for end in range(idx + 1,n + 1):
                if s[idx : end] in word and dfs(end):
                    vis[idx] = True
                    return True
            vis[idx] = False
            return False
        return dfs(0)

if __name__ == "__main__":
    ans = Solution()
    print(ans.wordBreak(("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"),
    ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]))
