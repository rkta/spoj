#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    int a;
    int b;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", (a*b));
    }
    return 0;
}
