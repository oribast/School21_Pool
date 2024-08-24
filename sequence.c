#include <stdio.h>

int main() {
    int max = 0, value;

    while (scanf("%d", &value) && value != -1) {
        if (value > max) {
            max = value;
        }
    }

    printf("%d", max);

    return 0;
}
