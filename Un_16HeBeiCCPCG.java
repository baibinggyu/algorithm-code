import java.util.Scanner;
public class Un_16HeBeiCCPCG {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        final int N = (int)1e6 + 5;
        StringBuilder sb = new StringBuilder(N * 2);
        while(t > 0){
            long count = 0;
            int a = sc.nextInt(),b = sc.nextInt();
            for(int i = a;i <= b;i++)  
            {
                int s = i;
                while(s > 0){
                    if(s >= a) count++;
                    s = (s - 1) & i;
                }
            }
            sb.append(count).append('\n');
            t--;
        }
        System.out.print(sb);
        sc.close();
    }
}   