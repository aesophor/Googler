#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int aInt = 368;
	char str[15];
	sprintf(str, "%d", aInt);
	printf("%s\n", str);
}
