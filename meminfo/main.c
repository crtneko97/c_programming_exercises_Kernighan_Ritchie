#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[256];

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Print the first few lines to get an idea of memory stats
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}
