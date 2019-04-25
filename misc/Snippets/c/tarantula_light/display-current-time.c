#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	char time_buffer[20];
	time_t now = time(NULL);

	strftime(time_buffer, 20, "%d-%m-%Y %H:%M:%S", localtime(&now));
 	printf("%s", time_buffer);
}
