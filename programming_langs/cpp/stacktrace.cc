extern "C" {
#include <stdio.h>
#include <fcntl.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
}

using namespace std;

void segv_handler(int sig) {
    void* array[10];
    size_t size = backtrace(array, 10);

    int fd = open("/tmp/stacktrace.log", O_CREAT | O_WRONLY, 0600);
    backtrace_symbols_fd(array + 2, size - 2, fd);
    close(fd);
}

void baz() { printf("%d\n", *(int*) -1); } // segfault
void bar() { baz(); }
void foo() { bar(); }

int main() {
    signal(SIGSEGV, segv_handler);   // install segfault handler

    foo(); // foo(), bar(), baz(), baz() segfault

    return EXIT_SUCCESS;
}

