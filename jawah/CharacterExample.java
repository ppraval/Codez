public class characterexample {
    public static void main(String[] args) {
        Character ch = 'Z';
        boolean isLetter = Character.isLetter(ch);
        System.out.println("Is Z a character? " + isLetter);

        int unicode = Character.getNumericValue(ch);
        System.out.println("The numeric value of 'Z' is " + unicode);
    }
}   