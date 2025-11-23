import java.util.Scanner;
public class _2025ShaiHaiCPCG {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Integer n = sc.nextInt();
        int p = n + 1;
       while(isPrime(p) != true) p++;
        StringBuilder substr = new StringBuilder(n * n * 6);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                substr.append( (i * p + j  + 1) +  " ");
            substr.append('\n');
        }
        System.out.print(substr);
        sc.close();
    }
    public static boolean isPrime(int x){
        if(x == 1 || x == 0) return false;
        for(int i = 2;i <= x / i;i++){
            if(x % i == 0) return false;
        }
        return true;
    }
}
