import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class ConcurrencyTest {

    public static void main(String[] args) {
        Account account = new Account(1000);
        Withdrawer withdrawer = new Withdrawer(account);
        AccountReader accountReader = new AccountReader(account);
        
        ExecutorService executor = Executors.newCachedThreadPool();
        executor.execute(withdrawer);
        executor.execute(accountReader);
        executor.shutdown();
    }
    
}