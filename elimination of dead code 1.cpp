#include <stdio.h>

#define ENABLE_DEBUG 0

int main() {
    int x = 10;

#if ENABLE_DEBUG
    printf("Debug mode enabled.\n");
    printf("The value of x is: %d\n", x);
#else
    printf("Debug mode disabled.\n");
#endif

    // The following code block is dead code because it is never executed due to the condition above
    if (x > 5) {
        printf("x is greater than 5.\n");
    }

    return 0;
}

