import java.util.Collections;
import java.util.ArrayList;
import java.util.Scanner;
public class P1281 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
	int n = sc.nextInt(),k = sc.nextInt();
	int[] arr = new int[n];
	for(int i = 0;i < n;i++) arr[i] = sc.nextInt();
	int l  = 1, r = (int)1e6 + 5;
	int pre = -1;
	while(l < r){
		int mid = l + ((r - l ) >> 1);
		if(check(arr,n,k,mid) == false){
			l = mid + 1;		
		}else{
			pre = mid;
			r = mid;
		}	
	}		
	int[] temp  = new int[k];
	ArrayList<Integer> res = new ArrayList<>();
	int cur = 0;
	res.add(n);
	for(int i = n - 1;i >= 0;i--){
		temp[cur] += arr[i];
		if(temp[cur] > pre){
			i++;
			res.add(i + 1);
			res.add(i);
			cur++;	
		}
	}	
	res.add(1);

	Collections.reverse(res);	
	StringBuilder sb = new StringBuilder(1 << 20);
	for(int i = 0;i < res.size();i++){
		sb.append(res.get(i) + " ");
		if((i & 1) == 1) sb.append('\n');
	}
	System.out.print(sb);
	sc.close();
    }
    public static boolean check(int[] arr,int n,int k,int avg){
	 int[] temp = new int[k];
	 for(int i = n - 1,cur = 0;i >= 0;i--){
		temp[cur] += arr[i];
		if(temp[cur] > avg){
			i++;
			cur++;
		}
		if(cur == k) return false;
	 }	 
	return true;	
    }
}
