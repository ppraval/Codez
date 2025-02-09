import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<Integer> arrList = new ArrayList<>();
        arrList.add(1);
        arrList.add(2);
        arrList.add(3);
        arrList.add(4);
        arrList.add(5);
        arrList.add(6);
        System.out.println("Printing the array list using indexes");
        for(int i = 0; i < arrList.size(); i++)
        {
            System.out.println(arrList.get(i));
        }
        System.out.println("Now we try to print stuff out normally using iters");
        for(int num : arrList)
        {
            System.out.println(num);
        }
    }
}