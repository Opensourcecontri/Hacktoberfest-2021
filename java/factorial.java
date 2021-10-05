import java.util.*;

public class factorial {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the element");
        int n = scan.nextInt();
        int i, mul = 1;
        for (i = 1; i <= n; i++)
            mul = mul * i;
        System.out.println("Factorial of" + n + " is " + mul);
    }
}