class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        arr = [0 for _ in range(n)]
        if s[0] == '0':
            return 0
        arr[0] = 1
        if n >= 2:
            if s[1] == '0':
                if s[0] in "12":
                    arr[1] = 1
                else:
                    return 0
            elif s[1] in "123456":
                if s[0] in "12":
                    arr[1] = 2
                else:
                    arr[1] = 1
            else:
                if s[0] == '1':
                    arr[1] = 2
                    # print("this is correct!")
                else:
                    arr[1] = 1
                    # print("this is error!")

        print(arr)
        for i in range(2,n):
            if s[i] == '0':
                if s[i - 1] in "03456789":
                    return 0
                else:
                    arr[i] = arr[i - 2]
            elif s[i] in "123456":
                if s[i - 1] in "12":
                    arr[i] = arr[i - 1] + arr[i - 2]
                    # print("this is 6!!!")
                    # print(arr[i])
                elif s[i - 1] in "34567890":
                    arr[i] = arr[i - 1]
            else:
                if s[ i - 1] == '1':
                    arr[i] = arr[i - 1] + arr[i - 2]
                else:
                    arr[i] = arr[i - 1]
                
        return arr[-1]
if __name__ == "__main__":
    test = Solution()
    test.numDecodings("17")
