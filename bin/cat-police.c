#include <stdio.h>

int main() {
    int b = '\n';
    for (int c; c = getchar_unlocked(), c != EOF; b = c)
        putchar_unlocked(c);
    if (b = b != '\n')
        puts("\nCAT-POLICE: Include '\\n' before EOF");
    return b;
}
