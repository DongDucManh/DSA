import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = 10;
        int b = sc.nextInt();
        int c = a + b;
        System.out.println("Sum of a and b is: " + c);
        System.out.println("Hello World!");
        sc.close();
    }
}