#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 1;

	{
		int b = 3;
		printf("I'm b, I'll die very very soon... b = %d\n", b);
	}

	printf("now b is dead. let's print a: %d\n", a);
	
	return 0;
}
