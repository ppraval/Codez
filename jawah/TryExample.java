public class TryExample {
    public static void main(String[] args) {
        try {
            int a = 10;
            int b = 0;
            int res = a / b;
            System.out.println("Res = " + res);
        }
        catch (ArithmeticException e) {
            System.out.println("Idot Can't divide by 0 You stupid imbecile");
        }
    }
}