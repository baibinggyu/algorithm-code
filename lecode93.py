from typing import List
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        curList = []
        def dfs(index : int):
            
            if index == len(s):
                if len(curList)  == 4:
                    res.append(".".join(curList))
                return 
            if s[index] == "0": 
                curList.append(s[index])
                dfs(index + 1)
                curList.pop()
            else:
                for i in range(index,index + 3):
                    if i + 1 > len(s):
                        break
                    if int(s[index : i + 1]) > 255:
                        break
                    curList.append(s[index : i + 1])
                    dfs(i + 1)
                    curList.pop()
        dfs(0)
        return res

if __name__ == "__main__":
    test = Solution()
    # print(Solution.restoreIpAddresses(test,"101023"))
    print(test.restoreIpAddresses("101023"))