import java.util.Random;

public class PrintTask implements Runnable {

    private final static Random generator = new Random();
    private final String taskName;
    private final int sleepTime;

    public PrintTask(String name) {
        taskName = name;
        sleepTime = generator.nextInt(5000); // milliseconds.
    }

    @Override
    public void run() {
        
        try {
            System.out.printf("%s going to sleep for %d milliseconds.\n",
                taskName, sleepTime);
            Thread.sleep(sleepTime); // sleep() will throw a new Exception.
        } catch(InterruptedException e) {
            System.out.printf("%s done sleeping\n", taskName);
        }
        
        System.out.printf("%s done sleeping\n", taskName);
    }
    
}
