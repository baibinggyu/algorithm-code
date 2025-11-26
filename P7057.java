import java.io.*;
import java.util.*;

public class P7057 {
    static final int MAXN = 50000 + 10;
    static long n, t;
    static long[] a = new long[MAXN];   // price
    static long[] w = new long[MAXN];   // waiting time
    static long[] f = new long[MAXN];   // dp
    static Deque<Integer> q = new ArrayDeque<>();

    static boolean check(long x) {
        q.clear();
        q.addLast(1); 
        f[1] = w[1];  // 在 C++ 中，f[1] = f[q.front()] + w[i] = f[1] + w[1]，也就是 w[1]（且 w[1]=0）

        for (int i = 2; i <= n; i++) {

            while (!q.isEmpty() && q.peekFirst() < i - x)
                q.pollFirst();

            f[i] = f[q.peekFirst()] + w[i];

            while (!q.isEmpty() && f[q.peekLast()] >= f[i])
                q.pollLast();

            q.addLast(i);
        }

        return f[(int)n] <= t;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        n = fs.nextLong();
        t = fs.nextLong();

        t -= (n - 1);     // 与 C++ 完全一致的处理

        for (int i = 1; i < n; i++) {
            a[i] = fs.nextLong();
        }
        for (int i = 2; i < n; i++) {
            w[i] = fs.nextLong();
        }
        w[1] = 0;    // 因为 C++ 中 w[1] 默认是 0

        long l = 1, r = n - 1, mid;

        while (l < r) {
            mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        long ans = Long.MAX_VALUE;
        for (long i = l; i < n; i++) ans = Math.min(ans, a[(int)i]);

        System.out.println(ans);
    }

    // -------- FastScanner (比 Scanner 快非常多) ----------
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) { in = is; }

        private int read() throws IOException {
            if (ptr >= len) {
                ptr = 0;
                len = in.read(buffer);
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            long sign = 1, val = 0;
            int c = read();
            while (c <= ' ') c = read();
            if (c == '-') { sign = -1; c = read(); }
            for (; c > ' '; c = read())
                val = val * 10 + (c - '0');
            return val * sign;
        }
    }
}

