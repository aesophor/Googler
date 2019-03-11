class Student
{
	private String name;
	private int    chinese_sc;
	private int    english_sc;

	// generate random numbers in the constructor.
	public Student(String name, int chinese_sc, int english_sc)
	{
		this.name       = name;
		this.chinese_sc = chinese_sc;
		this.english_sc = english_sc;
	}

	// use this annotation and method,
	// to override the output of directly printing object.
    @Override
    public String toString()
    {
        return "[st:" + name + "," + chinese_sc + "," + english_sc + "," + (chinese_sc+english_sc)/2 + "]";
    }
}

public class override_anno
{
	public static void main(String[] argv)
	{
		Student s1 = new Student("John", 90, 100);
		Student s2 = new Student("Herry", 90, 90);

		System.out.println(s1);
		System.out.println(s1);
	}
}
