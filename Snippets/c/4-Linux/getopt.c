#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int result;

    while((result=getopt(argc, argv, "ab:c::")) != 1)
    {
        switch(result)
        {
            case 'a':
                printf("option=a, optopt=%c, optarg=%s\n", optopt, optarg);
                break;
            case 
        }
    }

    return 0;
}
