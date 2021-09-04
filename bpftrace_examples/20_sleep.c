#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

__attribute__((noinline))
void increment(__attribute__((unused)) int *i)
{
  (*i)++;
}

int
main(int argc, char *argv[])
{
    int i = 1;
    
    printf("My PID %d\n", getpid());
    
    while (i <= MAX) {
        sleep(1);
        printf("Sleep %d\n", i);
        increment(&i);
    }
    
    return 0;
}
