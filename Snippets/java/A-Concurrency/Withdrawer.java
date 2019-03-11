public class Withdrawer implements Runnable {
    
    private final Account account;
    
    public Withdrawer(Account account) {
        this.account = account;
    }
    
    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            account.withdraw(5.0);
            
            try {
                Thread.sleep(3000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }
    
}