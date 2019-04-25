#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("[*] You have give me %d parameter(s).\n", argc-1);
	printf("    The parameter(s) is/are: ");

	for(unsigned short int i=1; i<argc; i++)
	{
		printf("%s ", argv[i]);
	}

	// the first argument (argv[0]) is the path to the program. (e.g. ./argument or C:\argument)

	printf("\n");
	return 0;
}
