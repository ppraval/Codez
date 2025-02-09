import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ThrowsExample {
    public static void checkFile() throws FileNotFoundException {
        File file = new File("nonexistentfile.txt");
        Scanner reader = new Scanner(file); // This will cause FileNotFoundException
    }

    public static void main(String[] args) {
        try {
            checkFile();
        } catch (FileNotFoundException e) {
            System.out.println("File not found! " + e);
        }
    }
}