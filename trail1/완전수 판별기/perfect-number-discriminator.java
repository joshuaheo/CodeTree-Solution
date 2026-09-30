import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        int a=sc.nextInt();
        for(int i=1;i<a;i++)
        {
            if(a%i==0)
            {
                sum+=i;
            }
            if(sum>a)
            {
                System.out.print("N");
                return;
            }
        }
        if(sum==a)
        {
            System.out.print("P");
        }
        else{
            System.out.print("N");
        }
    }
}