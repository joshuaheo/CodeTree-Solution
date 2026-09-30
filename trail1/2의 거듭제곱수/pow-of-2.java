import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt=0;
        int a=sc.nextInt();
        while(true)
        {
            if(a==1)
            {
                break;
            }
            a/=2;
            cnt++;
        }
        System.out.printf("%d",cnt);
    }
}