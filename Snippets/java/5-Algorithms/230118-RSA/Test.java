import marcolab.crypto.RSA;
import java.util.Scanner;

public class Test
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        RSA rsa = new RSA(43, 59);
        
        int message;
        int ciphertext;
        
        System.out.println(rsa);
        
        System.out.print("Enter an integer to be encrypted: ");
        message = sc.nextInt();
        
        System.out.println(ciphertext = rsa.encrypt(message));
        System.out.println(rsa.decrypt(ciphertext));
    }
}
