import java.util.Vector;
import java.util.Iterator;

public class CastingExample {
    public static void main(String[] args) {
        Vector<String> vector = new Vector<>();
        vector.add("Geetha");
        vector.add("Meenakshi");

        Iterator iterator = vector.iterator();
        while (iterator.hasNext()) {
            String element = (String) iterator.next(); // Casting required
            System.out.println(element);
        }
    }
}