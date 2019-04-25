#include <stdio.h>
#include <stdlib.h>

#define GREET "Hello, "
#define THATGUY "Jimmy"
#define SENTENCE GREET THATGUY

int main(int argc, char** args) {
    printf("%s\n", SENTENCE);
}
