```cpp
// ----------- 最通俗 Lucas 模板 -----------
long long p;                 // 模数，必须是质数
vector<long long> fac, inv;

// 快速幂
long long qpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return r;
}

// 预处理 factorial 和 inverse factorial（只处理 0 ~ p-1）
void init(long long mod) {
    p = mod;
    fac.resize(p);
    inv.resize(p);
    fac[0] = 1;
    for (int i = 1; i < p; i++) fac[i] = fac[i - 1] * i % p;

    // 费马小定理求阶乘逆元表：inv[i] = fac[i]^(p-2)
    inv[p - 1] = qpow(fac[p - 1], p - 2);
    for (int i = p - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % p;
}

// 计算小组合数 C(n, k)（n, k < p）
long long smallC(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[k] % p * inv[n - k] % p;
}

// Lucas 主函数：计算 C(n, k) mod p
long long C(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    long long ans = 1;
    while (n > 0 || k > 0) {
        long long ni = n % p;
        long long ki = k % p;
        if (ki > ni) return 0;          // 这一位不够减 → 组合数为 0
        ans = ans * smallC(ni, ki) % p; // 这一位的组合
        n /= p;
        k /= p;
    }
    return ans;
}

```





```cpp
//暴力版本
long long Lucas(long long n, long long k, long long p) {
  if (k == 0) return 1;
  return (C(n % p, k % p, p) * Lucas(n / p, k / p, p)) % p;
}
```



