public class ThreadExample extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Extended Thread: " + i);
            try {
                Thread.sleep(500); // Pause for 500 milliseconds
            } catch (InterruptedException e) {
                System.out.println(e);
                System.out.println("I love gmr");
            }
        }
    }

    public static void main(String[] args) {
        ThreadExample threadExample = new ThreadExample();
        threadExample.start();
    }
}