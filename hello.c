#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc > 1) {
        char message[16] = "Hello ";
        strcat(message, argv[1]);
        puts(message);
        return 0;
    }

    printf("Hello GHAS\n");
    return 0;
}
