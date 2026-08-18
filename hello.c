#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc > 2) {
        printf(argv[2]);
    }

    if (argc > 1) {
        char message[16] = "Hello ";
        strncat(message, argv[1], sizeof(message) - strlen(message) - 1);
        puts(message);
        return 0;
    }

    printf("Hello GHAS\n");
    return 0;
}
