import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        double a = sc.nextInt();
        for(int i=0;i<a;i++)
        {
            int b=sc.nextInt();
            sum+=b;
        }
        System.out.printf("%d %.1f",sum,sum/a);
    }
}