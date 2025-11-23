import java.util.Scanner;
public class P13581{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[4];
		for(int i = 0;i < 4;i++) arr[i] = sc.nextInt();
		System.out.println(arr[0] * arr[2]);
		sc.close();
	}
}
