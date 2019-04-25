#include <stdio.h>
#include <unistd.h>

int main() {
    char buf[50] = {0};
    read(0, buf, sizeof(buf) / sizeof(char));
    printf("%s\n", buf);
}
