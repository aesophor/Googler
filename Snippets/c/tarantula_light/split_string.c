#include <stdio.h>
#include <string.h>

int main(void)
{
  
char* string;
char* temp;

string = strdup("admin/shell_exec@test_cmd");



if (string != NULL) {

  temp = string;
temp = strsep(&string, "@");
printf("%s\n", string);
}

  return 0;
}
