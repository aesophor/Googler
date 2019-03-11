public class Account {
    
    private double balance;
    
    public Account(double openingBal) {
        balance = openingBal;
    }
    
    public synchronized boolean withdraw(double amount) {
        if (balance >= amount) {
            System.out.println("The balance should be: " + (balance - amount) + " now.");
            try {
                // Simulate risks check.
                Thread.sleep(2000);
            } catch (InterruptedException ex) {
                return false;
            }
            balance -= amount;
            return true;
        }
        
        return false;
    }
    
    // If getBalance() is not a synchronized method, it means that
    // executing this method does not require acquiring the lock beforehand.
    // 
    // If another method (which is not synchronized) reads from the object,
    // it can still see the inconsistent state.
    public double getBalance() {
        return balance;
    }
    
}