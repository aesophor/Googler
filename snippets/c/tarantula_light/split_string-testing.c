#include<string.h>
#include<stdio.h>
int main()
{
    char input[64] = "admin/shell_exec@mate-terminal";
    char *p;
	char *tmp;
    p = strtok(input, "@");

    if(p)
    {
    printf("%s\n", p);
    }
    tmp = strtok(NULL, "@");
	printf("%s\n", tmp);
    
	system(tmp);
           
    return 0;
}
