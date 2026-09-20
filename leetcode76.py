import collections
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t) : return ""
        res = ""
        left = 0
        targetLeft = -1
        length = len(s) + 1
        hashTable = collections.Counter(t)
        count_char = collections.defaultdict(int)
        def check(hashTable,count_char)->bool:
            for temp in hashTable:
                if count_char[temp] < hashTable[temp]:
                    return False
            return True
        right = 0
        flag = False
        while right < len(s):
            if hashTable[s[right]] and flag:
                flag = False
            elif hashTable[s[right]] :
                count_char[s[right]] += 1
            if check(hashTable=hashTable,count_char=count_char):
                if length > right - left + 1:
                    length = right - left + 1
                    targetLeft = left
                count_char[s[left]] -= 1
                left += 1
                while left < right and not hashTable[s[left]]: 
                    left += 1
                right -= 1;
                flag = True
            right += 1

        return "" if targetLeft == -1 else s[targetLeft : targetLeft + length]   