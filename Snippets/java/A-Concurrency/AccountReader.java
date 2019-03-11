public class AccountReader implements Runnable {
    
    private final Account account;
    
    public AccountReader(Account account) {
        this.account = account;
    }
    
    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Reading balance without synchronization: " + account.getBalance());
            try {
                Thread.sleep(3000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }
    
}
