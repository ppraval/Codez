import java.util.ArrayList;
import java.util.Iterator;

public class IteratorExample {
    public static void main(String[] args) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        arrayList.add(1);
        arrayList.add(2);
        arrayList.add(3);
        arrayList.add(4);
        arrayList.add(5);

        Iterator<Integer> iterator = arrayList.iterator();
        while (iterator.hasNext()) {
            int number = iterator.next();
            System.out.println(number);
        }
    }
}
