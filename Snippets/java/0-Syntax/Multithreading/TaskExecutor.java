import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class TaskExecutor {
    
    public static void main(String[] args) {
        
        PrintTask task1 = new PrintTask("task1");
        PrintTask task2 = new PrintTask("task2");
        PrintTask task3 = new PrintTask("task3");
        
        System.out.println("Starting Executor");
        
        // Create ExecutorService to manage threads.
        ExecutorService threadExecutor = Executors.newCachedThreadPool();
        
        // Start threads and place in runnable state.
        threadExecutor.execute(task1);
        threadExecutor.execute(task2);
        threadExecutor.execute(task3);
        
        // Shut down worker threads when their tasks complete.
        threadExecutor.shutdown();
        
        System.out.println("Task started, main ends.\n");
    }
    
}
