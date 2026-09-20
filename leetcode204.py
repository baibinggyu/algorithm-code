class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 0 or n == 1 or n == 2:
            return  0
        isPrime = [True for i in range(n)]
        isPrime[0] = False
        isPrime[1] = False
        primes = []
        for i in range(2,n):
            if isPrime[i] :
                primes.append(i)
            for val in primes:
                if i * val >= n:
                    break
                isPrime[i * val] = False
                if i % val == 0 :
                    break
        return len(primes)