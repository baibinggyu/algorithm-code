import java.util.Scanner;
public class _16HeBeiCCPCM {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String str = sc.next();
        if(str.equals("MB")){
            System.out.println(n * 1000 + " KB");
        }else if(str.equals("MiB")){
            System.out.println(n * 1024 + " KiB");
        }
        sc.close();
    }

}