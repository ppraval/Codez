import java.util.Vector;
import java.util.Enumeration;

public class EnumerationExample {
    public static void main(String[] args) {
        Vector<Integer> vector = new Vector<>();
        vector.add(1);
        vector.add(2);
        vector.add(3);
        vector.add(4);
        vector.add(5);

        Enumeration<Integer> enumeration = vector.elements();
        while (enumeration.hasMoreElements()) {
            int number = enumeration.nextElement();
            System.out.println(number);
        }
    }
}