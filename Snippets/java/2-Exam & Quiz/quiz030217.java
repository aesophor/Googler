import java.security.SecureRandom;

class GradeBook
{
	private SecureRandom random = new SecureRandom();
	private int[] grades = new int[20];

	// default constructor.
	public GradeBook()
	{
		// generate random grade and save them to the array.
		generateGrade();
	}

	// the method to generate grades.
	private void generateGrade()
	{
		for(int i=0; i<grades.length; i++)
		{
			grades[i] = 0 + random.nextInt(100 - 0 + 1);
		}
	}

	// the method to output grade distribution.
	public void printGradeDist()
	{
		for(int i=0; i<10; i++)
		{
			int count      = 0;
			int currentMin = i*10;
			int currentMax = (i+1)*10-1;

			if(i == 9)
			{
				// overwrite currentMax.
				currentMax = 100;

				System.out.printf("%02d-%02d: ", currentMin, currentMax);
			}

			else
			{
				System.out.printf("%02d-%3d : ", currentMin, currentMax);
			}


			// iterate through the array.
			// if any of the grade is within this section, print it.
			for(int grade: grades)
			{
				if(grade>=currentMin && grade<=currentMax)
				{
					count += 1;
					System.out.print(grade + " ");
				}
			}

			System.out.println(count);

		}
	}

}

public class quiz030217
{
	public static void main(String[] argv)
	{
		GradeBook gb1 = new GradeBook();
		gb1.printGradeDist();
	}
}
