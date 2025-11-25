import java.util.Scanner;
public class P13717{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(),h = sc.nextInt();
		int[][] arr = new int[n][3];
		boolean flag = false;
		for(int i = 0;i < n;i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
			arr[i][2] = sc.nextInt();
			if(arr[i][0] > h && arr[i][1] > h && arr[i][2] > h){
				flag = true;
			}
		}
		if(flag) {
			System.out.println("impossible");
			sc.close();
			return ;
		}
		long sum = 0;
		for(int i = 0;i < n;i++){
			int a = arr[i][0] <= h ? Math.min(arr[i][1], arr[i][2]): 0x3f3f3f3f;
			int b = arr[i][1] <= h ? Math.min(arr[i][0], arr[i][2]) : 0x3f3f3f3f;
			int c = arr[i][2] <= h ? Math.min(arr[i][0], arr[i][1]) : 0x3f3f3f3f;
			sum += Math.min(a,Math.min(b,c));
		}
		System.out.println(sum);
		sc.close();
	}
}
