import java.util.Scanner;
public class P12854 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        StringBuilder sb = new StringBuilder(1 << 20);
        while(t-- > 0){
            long b = sc.nextLong(),d = sc.nextLong();
            long res = (long)Math.floor((b - 1)/ (d / gcd(b,d)));
            sb.append(res).append('\n');
        }
        System.out.print(sb);
        sc.close();
    }
    public static long  gcd(long x,long y){
        if(x == 0) return y;
        if(y == 0) return x;
        long a = x & 1 ,b = y & 1;
        if(a == 0 && b == 0) return gcd( x >> 1, y >> 1) << 1;
        if(a == 0) return gcd(x >> 1, y);
        if(b == 0) return gcd(x , y >> 1);
        return x > y ? gcd(x - y, y) : gcd(x , y - x);
    }
}


/*
    (a / b) * d + (c / d) * d  = b

    (a * d) / b + c = b
    b | (a * d) 
    
    (a * d) / b < b

    a * d < b * b
    b | (a * d)


    a * d = k * b;
    a = (k * b) / d
*/