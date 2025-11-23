import java.util.Arrays;
import java.util.Scanner;
public class P12804{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder(1 << 20);
		while(t-- > 0){
			int n = sc.nextInt();
			long[] arr = new long[n];
			for(int i = 0;i < n;i++) arr[i] = sc.nextInt();
			if(n == 1 || n == 2) {
				sb.append(0).append('\n');
				continue;
			}
			Arrays.sort(arr);			
			long sum = 0;
			for(int i = 0;i < n;i++) sum += arr[i];
			int res = 0;
			boolean flag = true;
			for(int i = n - 1;i >= 0 ;i--){
				sum -= arr[i];
				if(sum > arr[i]){
					sb.append(sum + arr[i]).append('\n');
					flag = false;
					break;		
				}
			}
			if(flag) sb.append(0).append('\n');
		}
		System.out.print(sb);
		sc.close();
	}
}
