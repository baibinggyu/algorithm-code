import java.util.Scanner;
public class P10858{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder(1 << 20);
		while(t-- > 0){
			long x = sc.nextLong(),y = sc.nextLong();
			long g = gcd(x,y);
			long target = x * y  / g / g;	
			sb.append(1 + " " + target).append('\n');
		}		
		System.out.print(sb);	
		sc.close();
	}
	public static long gcd(long a ,long b){
		if(a == 0) return b;
		if(b == 0) return a;
		long x = a & 1,y = b & 1;
		if(x == 0 && y == 0) return gcd(a >> 1,b >> 1) << 1;
		if(x == 0) return gcd(a >> 1,b);
		if(y == 0) return gcd(a,b >> 1);
		return a > b ? gcd(a - b,b) : gcd(a,b - a);
	}
}
