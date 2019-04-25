#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char string[] = "wow";
	
	/* 3. Use a pointer to an unsigned char to examine the bytes */
	//unsigned char *p = (unsigned char *)string;
	// NOTE: for size_t see https://stackoverflow.com/questions/131803/unsigned-int-vs-size-t#131833
	size_t i;
	for (i=0; i < sizeof(string); i++)
		// we use %c here because we know that the content are chars.
		// generally we should use %02x to examine it (because we dont know what is inside).
    	printf("%c\n", p[i]);

	// or just an easy version.
	/* 3. Use a pointer to an unsigned char to examine the bytes */
	char *p = string;
	for (int i=0; i < sizeof(string); i++)
		// we use %c here because we know that the content are chars.
		// generally we should use %02x to examine it (because we dont know what is inside).
    	printf("%c\n", p[i]);
	
	return 0;
}
