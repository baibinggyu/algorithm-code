import java.util.Scanner;
public class _16HeBeiCCPCB {
    public    static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            Integer t = sc.nextInt();
            while(t > 0){
                long n = sc.nextLong();
                if(n == 0) {
                    System.out.println(0);
                    t--;
                    continue;
                }
                long temp = n + 1;
                while((temp & 1) == 0){
                    temp >>= 1;
                }
                if(temp == 1){
                    System.out.println(n);
                    t--;
                    continue;
                }
                long top = 0;
                for(int i = 0;i < 64;i++){
                    if((n & (1l << i)) > 0l){
                        top  = i;
                    }
                }
                long res = 1;
                for(int i = 0;i < top;i++){
                    res |= (1l << i);
                }
                System.out.println(res);
                t--;
            }
            sc.close();
        }
    
}