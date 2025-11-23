import java.util.Scanner;
public class P9645 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int N = (int)1e6;
        StringBuilder sb = new StringBuilder(N << 1);
        while(t-- > 0){
            int x = sc.nextInt(),y = sc.nextInt(),z = sc.nextInt();
            int res = -1;
            int temp = x + y - z;
            if(temp < 0) {
                sb.append(res).append('\n');
            }else if(temp == 0){
                sb.append(z + 1) .append('\n');
            }else{
                if(temp <= z || y <= z) sb.append(res).append('\n');
                else {
                    sb.append(temp).append('\n');
                }
            }
            
        }
        System.out.print(sb);
        sc.close();
    }
}



// /*
//     x + y = z (mod p)
//     x + y - z = 0 (mod p)
//     x + y - z = kp
//      p > x and p > z

//
// */
