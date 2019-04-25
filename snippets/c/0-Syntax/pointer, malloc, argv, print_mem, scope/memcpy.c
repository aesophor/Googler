#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	int mem_size = 40;
	int *mptr = (int *)malloc(mem_size);
	printf("[*] I just allocated 40 bytes in memory! its mem_addr is: %p\n", mptr);

    printf("[*] Before memcpy dest = %s\n", mptr);

	memcpy(mptr, "wow_test_content", 16+1);
	printf("[*] After memcpy dest = %s\n", mptr);

	free(mptr);
	printf("[*] mem freed ;)\n");
	printf("mem addr is: %p\n", mptr);

	printf("[*] After mem freed = %s\n", mptr);
    
    return(0);
}
