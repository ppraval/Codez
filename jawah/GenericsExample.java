import java.util.ArrayList;
import java.util.Iterator;

public class GenericsExample {
    public static void main(String[] args) {
        ArrayList<String> arrayList = new ArrayList<>();
        arrayList.add("Hello");
        arrayList.add("World");

        Iterator<String> iterator = arrayList.iterator();
        while (iterator.hasNext()) {
            String element = iterator.next(); // No casting required
            System.out.println(element);
        }
    }
}
