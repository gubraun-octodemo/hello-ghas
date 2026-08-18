#include <unistd.h>
#include <stdio.h>
#include <string.h>

int create_report(const char *path) {
    if (access(path, W_OK) == 0) {     // Check
        FILE *file = fopen(path, "w"); // Use: path may have changed
        if (!file) return -1;

        fputs("report\n", file);
        fclose(file);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc > 2) {
        printf(argv[2]);
    }

    if (argc > 1) {
        char message[16] = "Hello ";
        strcat(message, argv[1]);
        puts(message);
        return 0;
    }

    create_report("/tmp/toctou.txt");
    return 0;
}
