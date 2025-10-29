import java.util.Scanner;

public class EquationSolver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float ya, yb, yc, y, a, b, c;

        do {
            System.out.println("Enter a and b: ");
            a = sc.nextFloat();
            b = sc.nextFloat();
            ya = a * a - 5 * a + 6;
            yb = b * b - 5 * b + 6;
            y = ya * yb;
        } while (y > 0);
        if (ya == 0) {
            System.out.println("The solution exist on point " + a);
        } else if (yb == 0) {
            System.out.println("The solution exist on point " + b);
        } else {
            do {
                c = (a + b) / 2;
                yc = c * c - 5 * c + 6;
                if ((ya * yc) < 0) {
                    b = c;
                    yb = yc;
                } else if ((yb * yc) < 0) {
                    a = c;
                    ya = yc;
                }
            } while (Math.abs(yc) > 0.0001);
            System.out.println("The solution exist on point " + c);
        }
    }
}