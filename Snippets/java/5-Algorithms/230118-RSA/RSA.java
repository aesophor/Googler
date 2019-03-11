package marcolab.crypto;

import java.security.SecureRandom;

public class RSA
{
    private SecureRandom r;
    
    private int n; // n = pq.
    private int e; // Encryption key.
    private int d; // Decryption key.
    
    // Calculate n using p, q.
    // Dispose of p, q after the process.
    public RSA(int p, int q)
    {
        r = new SecureRandom();
        
        n = p*q;
        e = genEncKey(r.nextInt() % 15, (p-1)*(q-1));
        
        d = genDecKey(e, (p-1)*(q-1));
    }
 
    private int gcd(int num1, int num2)
    {
        if(num2 == 0) { return num1; }
        return gcd(num2, num1 % num2);
    }

    private int revEuclid(int num1, int num2)
    {        
        int s = 0;
        int r = num2;
        
        int sOld = 1;
        int rOld = num1;
        
        int temp = 0;
        while(r != 0)
        {
            int quotient = rOld / r;    
            
            temp = r;
            r = rOld - quotient * r;
            rOld = temp;
            
            temp = s;
            s = sOld - quotient * s;
            sOld = temp;
        }
        
        return sOld;
    }

    private int modExp(int base, int e, int m)
    {
        int x = 1;
        int power = base % m;
        while(e != 0)
        {
            if(e%2 == 1) { x = (x*power) % m; }
            power = (power*power) % m;
            e /= 2;
        }
        return x;
    }

    private int genEncKey(int e, int t)
    {
        while( gcd(e,t) != 1 )
        {
            e = genEncKey(r.nextInt() % 15, t);
        }
        return e;
    }

    private int genDecKey(int e, int t)
    {
        int decKey = revEuclid(e, t);
        return decKey < 0 ? 0-decKey : decKey;
    }


    public int encrypt(int m)
    {
        // C = M^e mod n
        return modExp(m, e, n);
    }

    public int decrypt(int c)
    {
        // M = C^d mod n
        return modExp(c, d, n);
    }

    @Override
    public String toString()
    {
        String ret = "";
        ret += ("==> Encryption key e: " + e + "\n");
        ret += ("==> Decryption key d: " + d + "\n");
        return ret;
    }
}
