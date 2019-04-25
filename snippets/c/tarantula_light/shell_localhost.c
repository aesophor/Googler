#include <stdio.h>
#include <string.h>

int main(void)
{
  char input[30];
  char output[1024];

setbuf(stdout, output);

  do {
    gets(input);
    system(input);
    
    printf("%s\n", output);
  } while(strcmp(input,"exit\n"));

  return 0;
}
