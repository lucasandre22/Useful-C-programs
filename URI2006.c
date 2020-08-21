#include <stdio.h>

int main() {
    int t, i = 5, n = 0, j;
    scanf("%d", &t);
    while(i--) {
        scanf("%d", &j);
        n += j == t;
    }
    printf("%d", n);
    return 0;
}

