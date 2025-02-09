public class RunnableExample implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Runnable Thread: " + i);
            try {
                Thread.sleep(500); // Pause for 500 milliseconds
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

    public static void main(String[] args) {
        RunnableExample runnableExample = new RunnableExample();
        Thread thread = new Thread(runnableExample);
        thread.start();
    }
}