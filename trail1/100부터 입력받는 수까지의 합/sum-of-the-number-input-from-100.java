import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int a=sc.nextInt();
        int sum=0;
        for(int i=a;i<=100;i++)
        {
            sum+=i;
        }
        System.out.printf("%d",sum);
    }
}