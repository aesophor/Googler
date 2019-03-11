#include <stdio.h>

int main(void)
{
	// create a new array of type int.
	// NOTE: the length of int is 4 bytes. 
	// if we replace int with short, each interval observed below will be 2 bytes.
	int int_arr[4];

	// assign value to each elements.
	int_arr[0] = 1;
	int_arr[1] = 2;
	int_arr[2] = 3;
	int_arr[3] = 4;
	
	// print variables' addresses.
	for(int i=0; i<4; i++)
	{
		printf("int_arr[%d] is %d, its mem_addr is %p\n", i, int_arr[i], &int_arr[i]);
	}

	// use of a pointer.
	// NOTE: pointer itself carries the mem_addr of a variable.
	//       to link a pointer to a var, we assign/store that var's mem_addr to the pointer.
	//       also note that we can print int_ptr directly. &* is beating around the bush ;)
	int* int_ptr = &int_arr[3];
	void* void_ptr;
	printf("%p\n", int_ptr);
	printf("%p\n", int_ptr-1);
	printf("%p\n", int_ptr-2);

	// in a x86 system, all pointers' sizes are 4 bytes.
	// in a x64 system, all pointers' sizes are 8 bytes.
	printf("size of void pointer: %d\n", sizeof(int_ptr));
	
	return 0;
}
