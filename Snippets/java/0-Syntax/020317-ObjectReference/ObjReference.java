class Class1 {int var1;}

public class ObjReference
{
	public static void main(String[] argv)
	{
		Class1 c1, c2;
		c1 = c2 = new Class1();

		c2.var1 = 10;

		System.out.println("[*] showing var1 in c1: " + c1.var1);
		System.out.println("[*] showing var1 in c2: " + c2.var1);

		c1.var1 = 30;

		System.out.println("[*] showing var1 in c1: " + c1.var1);
		System.out.println("[*] showing var1 in c2: " + c2.var1);
	}
}
