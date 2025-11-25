import java.util.LinkedList;
import java.util.Queue;
import java.util.AbstractMap;
import java.util.Scanner;
public class P4760{
	static boolean[] vis;
	static boolean[] dir; //是否是正着
	static int[] num; // 分子
	static int[] den; // 分母
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			StringBuilder sb = new StringBuilder(1 << 15);	
			if(n == 1){
				for(int i = 0;i < 3;i++) sc.nextInt();
				System.out.println("1 clockwise");
				sc.close();
				return;
			}
			int[][] arr = new int[n][3];
			for(int i = 0;i < n;i++){
				arr[i][0] = sc.nextInt();
				arr[i][1] = sc.nextInt();
				arr[i][2] = sc.nextInt();
			}
			Queue<Integer> q = new LinkedList<>();
			vis = new boolean[n];
			dir = new boolean[n];
			num = new int[n];
			den = new int[n];
			q.offer(0);
			dir[0] = true;
			num[0] = 1;
			den[0] = 1;
			while(q.size() > 0){
				int index = q.poll();
				if(vis[index] == true) continue;
				vis[index] = true;	
				for(int i = 0;i < n;i++){
					if(vis[i] == true) continue;
					boolean flag = isTangent(arr[index][0],arr[index][1],arr[index][2],arr[i][0],arr[i][1],arr[i][2]);
					if(flag == true){
						q.offer(i);
						AbstractMap.SimpleEntry<Integer,Integer> pair =	SubFunciton(arr[0][2],arr[i][2]);
						num[i] = pair.getKey();
						den[i] = pair.getValue();
						dir[i] = !dir[index];	
					}				}
			}	
			for(int i = 0;i < n;i++){
				if(num[i] == 0){
					sb.append("not moving\n");
					continue;
				}
				if(num[i] == den[i]) {
					sb.append("1").append(" ");
					if(dir[i] == true) sb.append("clockwise").append('\n');
					else sb.append("counterclockwise").append('\n');
					continue;
				}else{
					if(den[i] != 1)
						sb.append(num[i]).append('/').append(den[i]).append(" ");
					else sb.append(num[i]).append(" ");
					if(dir[i] == true) sb.append("clockwise").append('\n');
					else sb.append("counterclockwise").append('\n');
					continue;
				}
			}
			System.out.print(sb);
		}
		sc.close();
	}
	public static boolean isTangent(int x1,int y1,int r1,int x2,int y2,int r2){
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == (r1 + r2) * (r1 + r2) ;
	}
	public static AbstractMap.SimpleEntry<Integer,Integer> SubFunciton(int a ,int b){
		int g = gcd(a,b);
		return new AbstractMap.SimpleEntry<>(a / g,b / g);
	}		
	public static int gcd(int a ,int b){
		if(a == 0) return b;
		if(b == 0) return a;
		int x = a & 1,y = b & 1;
		if(x == 0 && y == 0) return gcd(a >> 1,b >> 1) << 1;
		if(x == 0) return gcd(a >> 1,b) ;
		if(y == 0) return gcd(a,b >> 1);
		return a > b ? gcd(a - b,b) : gcd(a,b - a);
	}
}
