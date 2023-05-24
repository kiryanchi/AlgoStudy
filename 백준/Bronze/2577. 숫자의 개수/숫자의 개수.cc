#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);

    int result = a * b * c;

    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (result > 0) {
        count[result % 10]++;

        result = result / 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", count[i]);
    }

    return 0;
}