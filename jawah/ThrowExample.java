public class ThrowExample{
    public static void checkAge(int age) {
        if(age < 18){
            throw new ArithmeticException("You are underage, get out before you will get touched by a pedo");
        }
        else {
            System.out.println("Welcome Pedo, Lets touch kids");
        }
    }

    public static void main(String[] args){
        checkAge(17);    
    }
}