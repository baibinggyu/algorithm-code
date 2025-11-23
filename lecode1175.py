from math import perm
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        isPrime = [True] * (n + 1)
        isPrime[0] = False
        primes = []
        for i in range(2,n + 1):
            if isPrime[i]:
                primes.append(i)
            for val in primes:
                if i * val > n:
                    break
                isPrime[i * val] = False
                if i % val == 0:
                    break
        return (perm(len(primes)) * perm(n - len(primes))) % (10**9 + 7)
        