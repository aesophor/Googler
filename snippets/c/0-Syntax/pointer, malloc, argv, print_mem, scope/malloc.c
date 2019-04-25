#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int mem_size = 40;
	int *test_ptr = (int *)malloc(mem_size);
	printf("wow! I just allocated 40 bytes in memory! its mem_addr is: %p\n", test_ptr);
	free(test_ptr);
	printf("god damn! it's lost lol ;)\n");
	return 0;
}
