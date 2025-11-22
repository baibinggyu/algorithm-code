import java.util.Scanner;
public class P9825 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int o = n / 3;
        System.out.println((n - o) * o + (o * (o - 1) >> 1));
        sc.close();
    }
}



/*
    奇数 奇数 偶数
    奇数 偶数 奇数
    偶数 奇数 奇数
*/