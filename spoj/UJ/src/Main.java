import java.io.BufferedReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int d = sc.nextInt();
        while (n != 0 || d != 0) {
            BigInteger bi = new BigInteger("1");
            for (int i = 0; i < d; ++i)
                bi = bi.multiply(new BigInteger(Integer.toString(n)));
            System.out.println(bi);
            n = sc.nextInt(); d = sc.nextInt();
        }
    }
}

