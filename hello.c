#include <stdio.h>
#include <string.h>

static void codeql_buffer_overflow_test_case(const char *input)
{
    char buffer[8];
    strcpy(buffer, input);
    puts(buffer);
}

int main(int argc, char *argv[])
{
    if (argc > 2 && strcmp(argv[1], "--codeql-test") == 0) {
        codeql_buffer_overflow_test_case(argv[2]);
        return 0;
    }

    if (argc > 1) {
        char message[16] = "Hello ";
        strcat(message, argv[1]);
        puts(message);
        return 0;
    }

    printf("Hello GHAS\n");
    return 0;
}
