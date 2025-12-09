public class exception {
    public static void main(String[] args) {
        int x = 1;
        try {
            System.out.println("hi1");

            if (1 == x) {
                ArithmeticException eq = new ArithmeticException("x is unfortunately equal to 1 ;)");
                throw eq;
            }
            System.out.println("hi2");
        } 
        // catch (ArithmeticException ar) {
        //     System.out.println("Lol, didnt work!");
        // } 
        finally {
            System.out.println("Im executed either way :)");
            System.out.println("However many times I want");
            System.out.println("LOL");
        }
    }
}